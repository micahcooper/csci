%{
#include "symtab.h"
//#include "value.h"
#include <list>
#include "utility.cpp"
#define YYSTYPE val


using namespace std;

void yyerror( const char *msg );
void error( const char *msg );
int yylex( void );
extern int yylineno;
extern FILE* code;
extern char* file;
int debug = 1;
int deleteFile = 0;
int alloc;
int main_alloc;
int start=1;
int label_no= 1;
int predef_param;
symtab symbol_table;
procedure* last_proc;
%}

%token IDENT
%token VAR
%token COLON
%token COMMA
%token SEMI
%token LPAR
%token RPAR
%token IF
%token WHILE
%token PROCEDURE
%token BGN
%token ELSE
%token END
%token DO_KEYWORD
%token REPEAT
%token UNTIL
%token THEN
%token ADD_OP
%token SUB_OP
%token MUL_OP
%token DIV_OP
%token EQ
%token NE
%token LT
%token LE
%token GT
%token GE
%token STRING
%token FLOAT
%token UNSIGNED_INT
%token ASSIGN_OP
%token PROGRAM
%token PROGRAM_END
%token ERROR
%token EXP

%type <val.name> IDENT  
%type <val.list_val> identifier_list
%type <val.plist> parameter_group parameter_list
%type <val.eattr> factor term simple_expression expression number constant

%%
program:		
			program_header block 
			{
			}
			PROGRAM_END
			{
				symbol_table.close_scope();
			}
		|
			program_header block error
			{
				if(debug)
					printf( "#program#\n" );
				error( "'.' expected" );
				yyerrok;
				symbol_table.close_scope();
			}
	;		

program_header:
			PROGRAM IDENT SEMI
			{
				symbol_table.install( $2, new program($2) );	
				symbol_table.open_scope();
				symbol_table.installPredefinedIdents();
			}
		|	
			PROGRAM IDENT error
			{
				if(debug)
					printf( "program header\n" );
				error( "';' expected" );
				yyerrok;
				yyclearin;
				symbol_table.install( $2, new program($2) );	
				symbol_table.open_scope();
			}
		|
			PROGRAM error SEMI
			{
				if(debug)
					printf( "program header\n" );
				error( "indentifier expected" );
				//yyclearin;	
				yyerrok;
				symbol_table.open_scope();
			}
		|
			error IDENT SEMI
			{
				if(debug)
					printf( "program header\n" );
				error( "'program' expected" );
				yyerrok;
				//yyclearin;
				symbol_table.open_scope();
			}
	;

block:	
			declarations compound_statement
	;

declarations: 
			declarations declaration 
		|
			/*empty*/
	;

declaration: 
			VAR variable_decls
			{
				if( start )
				{
					main_alloc = 0;
					start = 0;
				}
				else
					alloc = 0;
			}
		|
			procedure_decl
	;

variable_decls: 
			variable_decls variable_decl
			{
				if( start == 0 )
					fprintf( code, "\talloc\t%d\n", alloc );
			}
		|
			variable_decl
			{
				if( start == 0 )
					fprintf( code, "\talloc\t%d\n", alloc );
			}
	;

variable_decl: 	
			identifier_list COLON IDENT SEMI
			{
				type* etype = symbol_table.lookupType( $3 );	
				int tp = etype->ident_type;
				list<char*>::iterator var_it;

				if( tp == TYPE_INT || tp == TYPE_FLT )
				{
					for(var_it=$1->begin(); var_it!=$1->end(); var_it++)
					{
						if(symbol_table.install( (*var_it), new variable(tp) ) == 0 )
							error("variable already defined");	
						//else
						//	fprintf(code, "\tpusha\t%d", ((variable*)symbol_table.lookupBinding(*var_it))->offset);
					}
				}
				else
				{
					error( "integer or real type exptected" ); 
				}
				if( start )
					main_alloc += $1->size();
				else
					alloc += $1->size();
			}
		|
			identifier_list COLON IDENT error
			{
				if(debug)
					printf( "variable_decl\n" );
				error( "';' expected" );
				yyclearin;
				//yyerrok;
			}
		|
			identifier_list COLON error SEMI
			{
				if(debug)
					printf( "variable_decl\n" );
				error( "identifier expected" );
				//yyclearin;
				yyerrok;
			}
		|
			identifier_list error IDENT SEMI
			{
				if(debug)
					printf( "variable_decl\n" );
				error( "':' expected" );
				//yyclearin;
				yyerrok;
			}
	;

procedure_decl: 
			procedure_header 
			block SEMI
			{
				symbol_table.close_scope();
				fprintf( code, "main\n" );
				fprintf( code, "\tenter\t0\n" );
				fprintf( code, "\talloc\t%d\n", main_alloc );
			}
		|
			procedure_header block error
			{
				if(debug)
					printf( "procedure_decl" );
				error( "';' expected" );
				yyerrok;
			}
	;

procedure_header: 
			PROCEDURE 
			IDENT 
			{
				if( symbol_table.lookup($2) == Entry::unknown)
				{
					symbol_table.install( $2, new procedure() );
					last_proc = (procedure*)symbol_table.lookupBinding( $2 );
				}
				else
				{
					last_proc = NULL;
					error("procedure already defined");
				}
				symbol_table.open_scope();
				start= 0;
			}
			LPAR 
			parameter_list 
			RPAR 
			SEMI
			{
				list<Param*>::iterator it;
				it = $5->begin();
				char* label;
				int id;

				//for each param on $5
				while( it != $5->end() )
				{
					symbol_table.update_proc( last_proc, (*it) );
					it++;
				}
				
				label = get_label_name( $2 );
				((procedure*)symbol_table.lookupBinding($2))->label_name = label;
				id = getLabel();
				((procedure*)symbol_table.lookupBinding($2))->unique_id = id;
				fprintf( code, "$%s%d\n", label, id );
			}
		|
			PROCEDURE IDENT error parameter_list RPAR SEMI
			{
				if(debug)
					printf( "#procedure_header3#\n" );
				error( "'(' expected" );
				yyerrok;
			}
		|
			PROCEDURE IDENT error
			{
				if(debug)
					printf( "#procedure_header4#\n" );
				error( "';' expected" );
				//yyclearin;
				yyerrok;
			}
		|
			PROCEDURE error SEMI
			{
				if(debug)
					printf( "#procedure_header4#\n" );
				error( "identifier expected" );
				//yyclearin;
				yyerrok;
			}
		|
			PROCEDURE IDENT SEMI
			{
				char* label;
				int id;

				if( symbol_table.lookup($2) == Entry::unknown)
				{
					symbol_table.install( $2, new procedure() );
				}
				else
				{
					error("procedure already defined");
				}
				symbol_table.open_scope();
				label = get_label_name( $2 );
				((procedure*)symbol_table.lookupBinding($2))->label_name = label;
				id = getLabel();
				((procedure*)symbol_table.lookupBinding($2))->unique_id = id;
				fprintf( code, "$%s%d\n", label, id );
				start = 0;
			}
	;
parameter_list: 
			parameter_group
			{
				$$ = $1;
			}
		|
			parameter_list SEMI parameter_group
			{
				list<Param*>::iterator it; 
				$$ = $1;
				for( it=$3->begin(); it!=$3->end(); it++)
					$$->push_back(*it);
			}
		|
			parameter_list error parameter_group
			{
				if(debug)
					printf( "parameter_list" );		
				error( "';' expected" );
				yyerrok;
			}
	;

parameter_group: 
			identifier_list COLON IDENT
			{
				int tp;
				$$ = new list< Param* >;
				list<char*>::iterator it;
				Param* p;
				char* temp;

				tp = symbol_table.lookupIdentType( $3 );	
				//check for appropriate type??
				if( tp == TYPE_INT || tp == TYPE_FLT )
				{
					it = $1->begin();
					//for( it=$1->begin(); it!=$1->end(); it++);
					while( it != $1->end() )
					{
						p = new Param();
						p->tp = tp;
						p->ppc = BY_VAL;
						$$->push_back( p );
						if(symbol_table.install( (*it), new parameter(tp, BY_VAL) )== 0)
							error("parameter should be passed by reference");	
						it++;
					}
				}
				else
				{
					error( "incorrect variable declaration" );
				}
			}
	|
			VAR identifier_list COLON IDENT
			{
				int tp;
				$$ = new list< Param* >;
				list<char*>::iterator it;
				Param* p;

				tp = symbol_table.lookupIdentType( $4 );	
				//check for appropriate type??
				if( tp == TYPE_INT || tp == TYPE_FLT )
				{
					it = $2->begin();
					//for( it=$1->begin(); it!=$1->end(); it++);
					while( it != $2->end() )
					{
						p = new Param();
						p->tp = tp;
						p->ppc = BY_REF;
						$$->push_back( p );
						symbol_table.install( (*it), new parameter(tp, BY_VAL) );	
						it++;
					}
					//for( it=$2->begin(); it!=$2->end(); it++);
					//{
					//	p->tp = tp;
					//	$$->push_back( p );
					//	symbol_table.install( *it, new parameter(tp, BY_REF) );	
					//}
				}
				else
				{
					if(debug)
						printf( "parameter_group" );
					error( "incorrect variable declaration" );
				}
			}
		|
			VAR identifier_list COLON error
			{
				if(debug)
					printf( "parameter_group" );
				error( "missing type" );
				yyerrok;
			}
		|
			VAR identifier_list error IDENT
			{
				if(debug)
					printf( "parameter_group" );
				error( "':' expected" );
				yyerrok;
			}
	;

compound_statement: 
			BGN statement_list 
			{
				fprintf( code, "\treturn\n" );
			}
			END
		|
			BGN statement_list error
			{
				if(debug)
					printf( "compound_statement\n");
				error( "reached end of file while parsing" );
				yyclearin;
				yyerrok;
			}
	;

statement_list: 
				statement 
		|	
				statement_list SEMI statement
		|
				statement_list error statement
				{
					error( "';' expected");
					yyerrok;
					yyclearin;
				}
	;

statement: 
			/*empty*/
		|
			proc_call
		|
			IDENT ASSIGN_OP 
			{
				Entry* lhs = symbol_table.lookupBinding($1);
				int scope_difference = symbol_table.get_current_scope()-symbol_table.lookup_level($1);

				if( lhs->getType() == Entry::parameter )
				{
					if( ((parameter*)lhs)->ppc == BY_REF )
					{
						if( scope_difference = 0 )
							fprintf( code, "\tpushI\t%d\n", ((parameter*)lhs)->offset );
						if( scope_difference > 0 )
							fprintf( code, "\tpushgI\t%d, %d", scope_difference, ((parameter*)lhs)->offset );
					}
				}
			}
			expression
			{
				Entry::EntryType etype = symbol_table.lookup($1);
				Entry* lhs;
				int scope_difference = symbol_table.get_current_scope()-symbol_table.lookup_level($1);

				if( etype == Entry::variable || etype == Entry::parameter )
				{
					if( symbol_table.lookupIdentType($1) == TYPE_INT )
					{
						if( $4->tp != TYPE_INT )
							error( "incorrect assignment, integer expected" );
					}	
					else if( symbol_table.lookupIdentType($1) == TYPE_FLT )
					{
						if( $4->tp == TYPE_INT || $4->tp == TYPE_FLT){}
						else
							error("incorrect assignment, non-number");
					}
				}
				else if( etype == Entry::unknown )
					error( "undefined variable" );
				else
					error( "incorrect type" );

				if( etype == Entry::variable  )
				{
					lhs = (variable*)symbol_table.lookupBinding($1);
					if( scope_difference == 0 )
					{
						//we have a local variable
						if( ((variable*)lhs)->type == TYPE_INT )
						{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchI\n" ); 
							if( $4->tp == TYPE_FLT )
							{
								//fprintf( code, "\tflt\n" );
								//fprintf( code, "\tpopR\n" );
							}
							if( $4->tp == TYPE_INT )
								fprintf( code, "\tpopI\t%d\n", ((variable*)lhs)->offset );
						}
						if( ((variable*)lhs)->type == TYPE_FLT )
						{
							fprintf( code, "\tfetchR\n" );
							fprintf( code, "\tpopR\t%d\n", ((variable*)lhs)->offset );
						}
					}

					if( scope_difference > 0 )
					{
						//we have a non-local variable
						if( ((variable*)lhs)->type == TYPE_INT )
						{
							if( $4->lval == 1 )
							fprintf( code, "\tfetchI\n" ); 
							if( $4->tp == TYPE_FLT )
							{
								//fprintf( code, "\tflt\n" );
								//fprintf(code,"\tpopgR\t%d, %d\n",symbol_table.get_current_scope()-symbol_table.lookup_level($1),((variable*)lhs)->offset);
							}
							if( $4->tp == TYPE_INT )
								fprintf(code,"\tpopgI\t%d, %d\n", scope_difference,((variable*)lhs)->offset );
						}
						if( ((variable*)lhs)->type == TYPE_FLT )
						{
							fprintf( code, "\tfetchR\n" );
							fprintf( code, "\tpopgR\t%d, %d\n",scope_difference,((variable*)lhs)->offset );
						}
					}
				
				}//LHS=variable
				else if( etype == Entry::parameter )
				{
					lhs = (parameter*)symbol_table.lookupBinding($1);
					if( scope_difference == 0 )
					{
						//found a LOCAL parameter passed by value
						if( ((parameter*)lhs)->ppc == BY_VAL )
						{
							if( ((parameter*)lhs)->type == TYPE_INT )
							{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchI\n" );
								if( $4->tp == TYPE_FLT )
								{
									//fprintf( code, "\tflt\n" );
									//fprintf(code,"\tpopR\t%d, %d\n",symbol_table.get_current_scope()-symbol_table.lookup_level($1),((parameter*)lhs)->offset);
								}
								if( $4->tp == TYPE_INT )
								{
									fprintf(code,"\tpopI\t%d\n",((parameter*)lhs)->offset );
								}
							}
							if( ((parameter*)lhs)->type == TYPE_FLT )
							{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchR\n" );
								if( $4->tp == TYPE_INT )
									fprintf( code, "\tflt\n" );
								fprintf(code,"\tpopR\t%d, %d\n",((parameter*)lhs)->offset );
							}
						}//LOCAL parameter BY_VAL

						if( ((parameter*)lhs)->ppc == BY_REF )
						{
							//fprintf( code, "\tpushI\t%d\n", ((parameter*)lhs)->offset);
							if( ((parameter*)lhs)->type == TYPE_INT )
							{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchI\n" ); 
								if( $4->tp == TYPE_FLT )
								{
									//fprintf( code, "\tflt\n" );
									//fprintf(code,"\tpopgR\t%d, %d\n",symbol_table.get_current_scope()-symbol_table.lookup_level($1),((parameter*)lhs)->offset);
								}
								if( $4->tp == TYPE_INT )
									fprintf(code,"\tpopiI\t%d\n",((parameter*)lhs)->offset );
							}
							if( ((variable*)lhs)->type == TYPE_FLT )
							{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchR\n" );
								if( $4->tp == TYPE_INT )
									fprintf( code, "\tflt\n" );
								fprintf( code, "\tpopiR\t%d\n",((parameter*)lhs)->offset );
							}
						}//LOCAL parameter BY_REF
					}//LOCAL parameter
					if( scope_difference > 0 )
					{
						//found a NON-LOCAL parameter passed by value
						if( ((parameter*)lhs)->ppc == BY_VAL )
						{
							if( ((parameter*)lhs)->type == TYPE_INT )
							{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchI\n" );
								if( $4->tp == TYPE_FLT )
								{
									//fprintf( code, "\tflt\n" );
									//fprintf(code,"\tpopR\t%d, %d\n",symbol_table.get_current_scope()-symbol_table.lookup_level($1),((parameter*)lhs)->offset);
								}
								if( $4->tp == TYPE_INT )
								{
									fprintf(code,"\tpopgI\t%d, %d\n",scope_difference,((parameter*)lhs)->offset );
								}
							}
							if( ((parameter*)lhs)->type == TYPE_FLT )
							{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchR\n" );
								if( $4->tp == TYPE_INT )
									fprintf( code, "\tflt\n" );
								fprintf(code,"\tpopgR\t%d, %d\n", scope_difference ,((parameter*)lhs)->offset );
							}
						}//NON-LOCAL parameter BY_VAL

						if( ((parameter*)lhs)->ppc == BY_REF )
						{
							//fprintf( code, "\tpushgI\t%d, %d\n", scope_difference, ((parameter*)lhs)->offset );
							if( ((parameter*)lhs)->type == TYPE_INT )
							{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchI\n" ); 
								if( $4->tp == TYPE_FLT )
								{
									//fprintf( code, "\tflt\n" );
									//fprintf(code,"\tpopgR\t%d, %d\n",symbol_table.get_current_scope()-symbol_table.lookup_level($1),((parameter*)lhs)->offset);
								}
								if( $4->tp == TYPE_INT )
									fprintf(code,"\tpopiI\t%d\n",((parameter*)lhs)->offset );
							}
							if( ((variable*)lhs)->type == TYPE_FLT )
							{
								fprintf( code, "\tfetchR\n" );
								if( $4->tp == TYPE_INT )
									fprintf( code, "\tflt\n" );
								fprintf( code, "\tpopiR\t%d\n",((parameter*)lhs)->offset );
							}
						}//NON-LOCAL parameter BY_REF
					}//NON-LOCAL parameter
				}//checking parameter
			}//expression
		|
			WHILE 
			{
				$<labels>$.first = getLabel();
				$<labels>$.second = getLabel();
				fprintf( code, "$%d\n", $<labels>$.first );
			}
			expression 
			{
				fprintf( code, "\tjumpz\t$%d\n", $<labels>2.second );
			}
			DO_KEYWORD statement
			{
				fprintf( code, "\tjump\t$%d\n", $<labels>2.first );
				fprintf( code, "$%d\n", $<labels>2.second );
			}
		|
			REPEAT 
			{
				$<labels>$.first = getLabel();
				$<labels>$.second = getLabel();
				fprintf( code, "$%d\n", $<labels>$.first );
			}
			statement_list 
			UNTIL 
			expression
			{
				fprintf( code, "\tjump\t$%d\n", $<labels>2.first );
			}
		|
			IF 
			{
				$<labels>$.first = getLabel();
				$<labels>$.second = getLabel();
			}
			expression 
			{
				fprintf( code, "\tjumpz\t$%d\n", $<labels>2.second );
			}
			THEN 
			statement
			{
				fprintf( code, "$%d\n", $<labels>2.second );
			}
		|
			IF 
			{
				$<labels>$.first = getLabel();
				$<labels>$.second = getLabel();
			}
			expression 
			{
				fprintf( code, "\tjumpz\t$%d\n", $<labels>2.first );
			}
			THEN 
			statement 
			{
				fprintf( code, "\tjump\t$%d\n", $<labels>2.second );
				fprintf( code, "$%d\n", $<labels>2.first );
			}
			ELSE 
			statement
			{
				fprintf( code, "$%d\n", $<labels>2.second );
			}
		|
			compound_statement
		|
			error
			{
				error( "not a statement" );
				yyerrok;
				yyclearin;
			}
	;
proc_call:
			IDENT
			{
				Entry* binding = symbol_table.lookupBinding( $1 );
				int id;
				char* label;
				char* temp;
				
				if( binding->getType() != Entry::procedure )
				{
					error( "procedure expected" );
				}
				else if( ((procedure*)binding)->param_no != 0) 
				{
					error( "call with no parameters supplied" );
				}
				fprintf( code, "\tenter\t%d\n", symbol_table.get_current_scope()-(symbol_table.lookup_level($1)) );
				if( ((procedure*)symbol_table.lookupBinding($1))->already_defined == 1 )
				{
					fprintf( code, "\tcall\t$%s, %d\n", "WriteLn", 0 );
				}
				else
				{
					id = ((procedure*)binding)->unique_id;
					label = ((procedure*)binding)->label_name;
					fprintf( code, "\tcall\t$%s%d, %d\n", label, id, 0 );
				}
			}
		|
			proc_call_w_params
	;	
proc_call_w_params:
			name_and_params RPAR
			{
				char* label_name = ((procedure*)$<entry>1)->label_name;
				int id = ((procedure*)$<entry>1)->unique_id;

				if( ((procedure*)$<entry>1)->already_defined == 1 )
				{
					int proc_id = ((procedure*)$<entry>1)->proc_id;
					int p_type = ((procedure*)$<entry>1)->param_vector.at(0)->tp;
					if( proc_id == 1 )
					{
						//we have write
						if( predef_param == TYPE_INT )
							fprintf( code, "\tcall\t%s, %d\n", "$WriteInt", 1 );
						else if( predef_param == TYPE_FLT )
							fprintf( code, "\tcall\t%s, %d\n", "$WriteReal", 1 );
						else
							fprintf( code, "\tcall\t%s, %d\n", "$WriteStri", 1 );
					}
					if( proc_id == 2)
					{
						//we have writeln
					}
					if( proc_id == 3)
					{
						if( predef_param == TYPE_INT )
							fprintf( code, "\tcall\t%s, %d\n", "$ReadInt", 1 );
						else if( predef_param == TYPE_FLT )
							fprintf( code, "\tcall\t%s, %d\n", "$ReadReal", 1 );
					}
				}
				else
				{
					fprintf( code, "\tcall\t$%s%d, %d\n", label_name, id, ((procedure*)$<entry>1)->get_no_of_params() );
				}
			}
		|
			name_and_params error
			{
				if(debug)
					printf( "#statement#\n" );
				error( "')' expected" );
				yyerrok;
			}
	;	
name_and_params:
			IDENT error expression 
			{
				if(debug)
					printf( "#statement#\n" );
				error( "'(' expected" );
				yyerrok;
			}
		|
			IDENT 
			{
				$<entry>$ = symbol_table.lookupBinding($1);
				if( $<entry>$->getType() != Entry::procedure )
					error( "procedure expected" );
			}
			LPAR 
			{
					fprintf( code, "\tenter\t%d\n", symbol_table.get_current_scope()-(symbol_table.lookup_level($1)) );
			}
			expression
			{
				Entry* binding = symbol_table.lookupBinding( $1 );
				vector<Param*>::iterator paramN;
				procedure* temp = (procedure*)symbol_table.lookupBinding( $1 );

				parNo = 1;
				paramN = temp->param_vector.begin();
				
				predef_param = $5->tp;
				//checking the first parameter
				if( ($5->tp == (*paramN)->tp) || (*paramN)->tp == TYPE_ANY )	
				{
					if( ($5->lval == 1 && (*paramN)->ppc == BY_VAL) )
					{
						if( $5->tp == TYPE_INT )
							fprintf( code, "\tfetchI\n" );
						if( $5->tp == TYPE_FLT )
							fprintf( code, "\tfetchR\n" );
						if( (*paramN)->tp == TYPE_FLT )
							fprintf( code, "\tflt\n" );
					}
				}//done checking the first param
				
				parNo++;
				$$.entry = $<entry>2;
			}
		|
			name_and_params
			COMMA
			expression
			{
				vector<Param*>::iterator paramN;
				paramN = ((procedure*)$<entry>1)->param_vector.begin();
				
				//checking the N parameter
				if( ($3->tp == (*paramN)->tp) || (*paramN)->tp == TYPE_ANY )	
				{
					if( $3->lval == 1 && (*paramN)->ppc == BY_VAL )
					{
						if( $3->tp == TYPE_INT )
							fprintf( code, "\tfetchI\n" );
						if( $3->tp == TYPE_FLT )
							fprintf( code, "\tfetchR\n" );
						if( (*paramN)->tp == TYPE_FLT )
							fprintf( code, "\tflt\n" );
					}
				}//done checking the first param
				
				parNo++;
				$$.entry = $<entry>1;
			}
		|
			name_and_params error expression
			{
				error( "',' expected" );
			}
	;

expression: 
			simple_expression
			{
				$$ = new ExprAttr();
				$$->tp = $1->tp;
				$$->lval = $1->lval;
			}
		|
			simple_expression 
			EQ 
			{
				if( $1->lval == 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
			simple_expression
			{
				$$ = new ExprAttr();
				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\teqI\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
					fprintf( code, "\teqR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
					fprintf( code, "\teqR\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\teqR\n" );

				$$->tp =TYPE_BOOL;	
				$$->lval = 0;
			}
		|
			simple_expression 
			NE 
			{
				if( $1->lval == 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
			simple_expression
			{
				$$ = new ExprAttr();
				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\tneI\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
					fprintf( code, "\tneR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
					fprintf( code, "\tneR\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\tneR\n" );

				$$->tp =TYPE_BOOL;	
				$$->lval = 0;
			}
		|
			simple_expression 
			LT 
			{
				if( $1->lval == 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
			simple_expression
			{
				$$ = new ExprAttr();
				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\tltI\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
					fprintf( code, "\tltR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
					fprintf( code, "\tltR\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\tltR\n" );

				$$->tp =TYPE_BOOL;	
				$$->lval = 0;
			}
		|
			simple_expression 
			LE 
			{
				if( $1->lval == 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
			simple_expression
			{
				$$ = new ExprAttr();
				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\tleI\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
					fprintf( code, "\tleR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
					fprintf( code, "\tleR\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\tleR\n" );

				$$->tp =TYPE_BOOL;	
				$$->lval = 0;
			}
		|
			simple_expression 
			GT 
			{
				if( $1->lval == 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
			simple_expression
			{
				$$ = new ExprAttr();
				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\tgtI\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
					fprintf( code, "\tgtR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
					fprintf( code, "\tgtR\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\tgtR\n" );

				$$->tp =TYPE_BOOL;	
				$$->lval = 0;
			}
		|
			simple_expression 
			GE 
			{
				if( $1->lval == 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
			simple_expression
			{
				$$ = new ExprAttr();
				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\tgeI\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
					fprintf( code, "\tgeR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
					fprintf( code, "\tgeR\n" );
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\tgeR\n" );

				$$->tp =TYPE_BOOL;	
				$$->lval = 0;
			}
	;

simple_expression: 
			term
			{
				$$ = new ExprAttr();
				$$->lval = $1->lval;
				$$->tp = $1->tp;
			}
		|
			ADD_OP term
			{
				$$ = $2;
				if( $2->lval == 1 )
				{
					if( $2->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $2->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
		|
			SUB_OP term
			{
				$$ = $2;
				if( $2->lval == 1 )
				{
					if( $2->tp == TYPE_INT )
					{
						fprintf( code, "\tfetchI\n" );
						fprintf( code, "\tnegI\n" );
					}
					if( $2->tp == TYPE_FLT )
					{
						fprintf( code, "\tfetchR\n" );
						fprintf( code, "\tnegR\n" );
					}
				}
				if( $2->lval == 0)
				{
					if( $2->tp == TYPE_INT )
						fprintf( code, "\tnegI\n" );
					if( $2->tp == TYPE_FLT )
						fprintf( code, "\tnegR\n" );
				}
			}
		|
			simple_expression 
			ADD_OP 
			{
					if( $1->tp == TYPE_INT && $1->lval == 1 )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT && $1->lval == 1 )
						fprintf( code, "\tfetchR\n" );
			}
			term
			{
				if( ($1->tp==TYPE_INT || $1->tp == TYPE_FLT) && ($4->tp==TYPE_INT || $4->tp==TYPE_FLT) )
				{
					if( $1->tp == TYPE_INT && $4->tp==TYPE_INT )
					{
						if( $4->lval == 1 )
						{
							fprintf( code, "\tfetchI\n" );
						}
						fprintf( code, "\taddI\n" );
						$$->tp==TYPE_INT;	
					}
					else
					{
						if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
						{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchR\n" );
						}
						if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
						{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchI\n" );
						}
						if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
						{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchR\n" );
						}
						$$->tp=TYPE_FLT;
						fprintf( code, "\taddR\n" ); 
					}
				}
				else
					error("illegal operands");

				$$->lval = 0;
			}
		|
			simple_expression 
			SUB_OP 
			{
					if( $1->tp == TYPE_INT && $1->lval == 1 )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT && $1->lval == 1 )
						fprintf( code, "\tfetchR\n" );
			}
			term
			{

				if( ($1->tp==TYPE_INT || $1->tp == TYPE_FLT) && ($4->tp==TYPE_INT || $4->tp==TYPE_FLT) )
				{
					if( $1->tp == TYPE_INT && $4->tp==TYPE_INT )
					{
						if( $4->lval == 1 )
						{
							fprintf( code, "\tfetchI\n" );
						}
						fprintf( code, "\tsubI\n" );
						$$->tp==TYPE_INT;	
					}
					else
					{
						if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
						{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchR\n" );
						}
						if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
						{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchI\n" );
						}
						if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
						{
							if( $4->lval == 1 )
								fprintf( code, "\tfetchR\n" );
						}
						$$->tp=TYPE_FLT;
						fprintf( code, "\tsubR\n" ); 
					}
				}
				else
					error("illegal operands");

				$$->lval = 0;
			}
	;

term:
			factor
			{
				$$ = $1;
			}
		|
			term
			MUL_OP 
			{
				if( $1->lval== 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR" );
				}
			} 
			factor
			{
				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR" );
				}

				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
				{
					fprintf( code, "\tflt\n" );
					fprintf( code, "\tmulR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
				{
					fprintf( code, "\tfltb\n" );
					fprintf( code, "\tmulR\n" );
				}
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\tmulR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\tmulI\n" );
			}
		|
			term 
			DIV_OP 
			{
				if( $1->lval== 1 )
				{
					if( $1->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $1->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}
			}
			factor
			{

				if( $4->lval == 1 )
				{
					if( $4->tp == TYPE_INT )
						fprintf( code, "\tfetchI\n" );
					if( $4->tp == TYPE_FLT )
						fprintf( code, "\tfetchR\n" );
				}

				if( $1->tp == TYPE_FLT && $4->tp == TYPE_INT )
				{
					fprintf( code, "\tflt\n" );
					fprintf( code, "\tdivR\n" );
				}
				if( $1->tp == TYPE_INT && $4->tp == TYPE_FLT )
				{
					fprintf( code, "\tfltb\n" );
					fprintf( code, "\tdivR\n" );
				}
				if( $1->tp == TYPE_FLT && $4->tp == TYPE_FLT )
					fprintf( code, "\tdivR\n" );
				if( $1->tp == TYPE_INT && $4->tp == TYPE_INT )
					fprintf( code, "\tdivI\n" );
			}
	;

factor: 
			IDENT
			{
				Entry* binding = symbol_table.lookupBinding( $1 );
				
				if(binding->getType()==Entry::parameter)
				{
					$$ = new ExprAttr();
					$$->tp = ((parameter*)binding)->type;
					$$->lval = 1;
					
					if( symbol_table.lookup_level($1) == symbol_table.get_current_scope() )	
					{
						//cout<<$1<<" parameter is local"<<endl;
						if( ((parameter*)binding)->ppc == BY_VAL )
							fprintf( code, "\tpusha\t%d\n", ((parameter*)binding)->offset );	
						if( ((parameter*)binding)->ppc == BY_REF )
							fprintf( code, "\tpushI\t%d\n", ((parameter*)binding)->offset );
					}
					if( symbol_table.lookup_level($1) < symbol_table.get_current_scope() )
					{
						//cout<<$1<<" parameter is non-local"<<endl;
						if( ((parameter*)binding)->ppc == BY_VAL )
							fprintf(code,"\tpushga\t%d, %d\n",(symbol_table.get_current_scope()-symbol_table.lookup_level($1)),((parameter*)binding)->offset );
						if( ((parameter*)binding)->ppc == BY_REF )
							fprintf(code,"\tpushgI\t%d, %d\n",(symbol_table.get_current_scope()-symbol_table.lookup_level($1)),((parameter*)binding)->offset );
					}
				}
				else if(binding->getType()==Entry::variable)
				{
					$$ = new ExprAttr();
					$$->tp = ((variable*)binding)->type;
					$$->lval = 1;
	
					if( symbol_table.lookup_level($1) == symbol_table.get_current_scope() )	
					{
						//cout<<$1<<" variable is local"<<endl;
						fprintf(code, "\tpusha\t%d\n", ((variable*)binding)->offset );
					}
					if( symbol_table.lookup_level($1) < symbol_table.get_current_scope() )
					{
						//cout<<$1<<" variable is non-local"<<endl;
						fprintf(code,"\tpushga\t%d, %d\n",(symbol_table.get_current_scope()-symbol_table.lookup_level($1)),((variable*)binding)->offset );
					}
				}
				else
				{
					if( binding->getType()==Entry::unknown )
						error("undeclared variable");
					else
						error( "incompatible types in assignment" );
				}
			}
		|
			constant
			{
				$$ = $1;
			}
		|
			LPAR expression RPAR
		|
			LPAR expression error
			{
				if(debug)
					printf( "factor" );
				error( "')' expected" );
				yyerrok;
			}
		|
			error expression RPAR
			{
				if(debug)
					printf( "factor" );
				error( "'(' expected" );
				yyerrok;
			}
	;

constant:
			number
			{
				$$ = $1;
			}
		|
			STRING
			{
				fprintf(code, "\tpushs %s\n", $1.val.name );
				$$ = new ExprAttr();
			}
		|
			error
			{
				if(debug)
					printf( "#constant#\n" );
				error( "syntax error" );
				//yyerrok;
				yyclearin;
			}
	;

number:
			UNSIGNED_INT
			{
				fprintf(code, "\tpushcI\t%s\n", $1.val.name );
				$$ = new ExprAttr();
				$$->tp = TYPE_INT;
				$$->lval = 0;
			}
		|
			FLOAT
			{
				fprintf(code, "\tpushcR\t%s\n", $1.val.name );
				$$ = new ExprAttr();
				$$->tp = TYPE_FLT;
				$$->lval = 0;
			}
	;

identifier_list:
			IDENT
			{
				list<char*>::iterator it;

				$$ = new list<char*>();
				$$->push_back( $1 );
				it=$$->begin();
//cout <<"ident_list->push_back("<<*it<<")"<<endl;
			
			}
		|
			identifier_list COMMA IDENT
			{
				//$1 = new list<char*>();
				$1->push_back( $3 );
				$$ = $1;		
			}
		|
			identifier_list COMMA error
			{
				if(debug)
					printf( "#identifier_list#" );
				error( "identifier expected" );
				yyerrok;
			}
		|
			identifier_list error IDENT
			{
				if(debug)
					printf( "#identifier_list#" );
				error( "',' expected" );
				yyerrok;
			}
	;

%%
extern int yylineno;

void yyerror( const char* msg )
{
//	fprintf( stderr, "Line %d: %s\n", yylineno, msg );
//	fflush( stderr );
}
void 
error( const char *msg )
{
	deleteFile = 1;
	fprintf( stderr, "Line %d: %s\n", yylineno, msg );
	printf("An ERROR has occurred please ignore %s!!\n", file );
	fflush( stderr );
}
