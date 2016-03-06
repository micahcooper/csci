%{
#include "symtab.h"
//#include "value.h"
#include <list>
#define YYSTYPE val


using namespace std;

void yyerror( const char *msg );
void error( const char *msg );
int yylex( void );
extern int yylineno;
int debug = 0;
symtab symbol_table ;
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
%token MUL_OP
%token REL_OP
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
%type <val.elist> expression_list 
%type <val.eattr> factor term simple_expression expression

%%
program:		
			program_header block PROGRAM_END
		|
			program_header block error
			{
				if(debug)
					printf( "#program#\n" );
				error( "'.' expected" );
				yyerrok;
			}
	;		

program_header:
			PROGRAM IDENT SEMI
			{
				symbol_table.install( $2, new program($2) );	
				symbol_table.open_scope();
			}
		|	
			PROGRAM IDENT error
			{
				if(debug)
					printf( "program header\n" );
				error( "';' expected" );
				yyerrok;
			}
		|
			PROGRAM error SEMI
			{
				if(debug)
					printf( "program header\n" );
				error( "indentifier expected" );
				//yyclearin;	
				yyerrok;
			}
		|
			error IDENT SEMI
			{
				if(debug)
					printf( "program header\n" );
				error( "'program' expected" );
				yyerrok;
				//yyclearin;
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
		|
			procedure_decl
	;

variable_decls: 
			variable_decls variable_decl
		|
			variable_decl
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
						symbol_table.install( (*var_it), new variable(tp) );	
				}
				else
				{
					error( "integer or real type exptected" ); 
				}
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
			procedure_header block SEMI
			{
				symbol_table.close_scope();
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
			PROCEDURE IDENT 
			{
				symbol_table.install( $2, new procedure() );
				last_proc = (procedure*)symbol_table.lookup( $2 );
				symbol_table.open_scope();
			}
			LPAR parameter_list RPAR SEMI
			{
				//for each param on $5
				//symbol_table.update_proc( last_proc, param);
				list<Param*>::iterator it;

				for( it=$5->begin(); it!=$5->end(); it++ )
				{
					symbol_table.update_proc( last_proc, (*it) );
				}
			}
		|
			PROCEDURE IDENT LPAR parameter_list RPAR error
			{
				if(debug)
					printf( "#procedure_header#\n" );
				error( "';' expected" );
				//yyclearin;
				yyerrok;
			}
		|
			PROCEDURE IDENT LPAR parameter_list error SEMI
			{
				//not indicated as needed by kochut
				if(debug)
					printf( "#procedure_header#\n" );
				error( "')' expected" );
				//yyclearin;
				yyerrok;
			}
		|
			PROCEDURE IDENT error parameter_list RPAR SEMI
			{
				if(debug)
					printf( "#procedure_header#\n" );
				error( "'(' expected" );
				yyerrok;
			}
		|
			PROCEDURE IDENT error
			{
				if(debug)
					printf( "#procedure_header#\n" );
				error( "';' expected" );
				//yyclearin;
				yyerrok;
			}
		|
			PROCEDURE error SEMI
			{
				if(debug)
					printf( "#procedure_header#\n" );
				error( "identifier expected" );
				//yyclearin;
				yyerrok;
			}
		|
			PROCEDURE IDENT SEMI
			{
				symbol_table.install( $2, new procedure() );
				symbol_table.open_scope();
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

				tp = symbol_table.lookupIdentType( $3 );	
				//check for appropriate type??
				if( tp == TYPE_INT || tp == TYPE_FLT )
				{
					for( it=$1->begin(); it!=$1->end(); it++);
					{
						p->tp = tp;
						p->ppc = BY_VAL;
						$$->push_back( p );
						symbol_table.install( *it, new parameter(tp, BY_VAL) );	
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
					for( it=$2->begin(); it!=$2->end(); it++);
					{
						p->tp = tp;
						p->ppc = BY_REF;
						$$->push_back( p );
						symbol_table.install( *it, new parameter(tp, BY_REF) );	
					}
				}
				else
				{
					error( "incorrect variable declaration" );
				}
			}
		|
			VAR identifier_list COLON error
			{
				if(debug)
					printf( "parameter_group" );
				error( "';' expected" );
				yyerrok;
			}
		|
			VAR identifier_list error SEMI
			{
				if(debug)
					printf( "parameter_group" );
				error( "':' expected" );
				yyerrok;
			}
	;

compound_statement: 
			BGN statement_list END
		|
			BGN statement_list error
			{
				if(debug)
					printf( "compound_statement\n");
				error( "reached end of file while parsing" );
				//yyclearin;
				yyerrok;
			}
		|
			error statement_list END
			{
				if(debug)
					printf("compound_statement\n");
				error( "'BEGIN' expected" );
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
				}
	;

statement: 
			/*empty*/
		|
			IDENT
			{
				Entry* binding = symbol_table.lookupBinding( $1 );
				
				if( binding->getType() != Entry::procedure )
				{
					error( "procedure expected" );
				}
				else if( ((procedure*)binding)->param_no != 0) 
				{
					error( "call with no parameters supplied" );
				}
			}
		|
			IDENT LPAR expression_list RPAR
			{
				Entry* binding = symbol_table.lookupBinding( $1 );

				if( binding->getType() != Entry::procedure )
					error( "procedure expected" );
				else if( $3->size() != ((procedure*)binding)->param_no )
					error( "incorrect number of parameters" );
				else
				{
					list<ExprAttr*>::iterator e_it;
					list<Param*>::iterator p_it;
					procedure* temp = (procedure*)symbol_table.lookupBinding( $1 );
					vector<Param*>* pv;

					for(e_it=$3->begin(); e_it!=$3->end(); e_it++ )
					{
						if( (*e_it)->tp == BY_REF )
							if( (*e_it)->lval == 0 )
								error( "incorrect expresion" );		
					}	
				}
			}
		|
			IDENT error expression_list RPAR
			{
				if(debug)
					printf( "#statement#\n" );
				error( "'(' expected" );
				yyerrok;
			}
		|
			IDENT LPAR expression_list error
			{
				if(debug)
					printf( "#statement#\n" );
				error( "')' expected" );
				yyerrok;
			}
		|
			IDENT ASSIGN_OP expression
			{
				Entry::EntryType etype = symbol_table.lookup($1);

				if( etype != Entry::variable || etype != Entry::parameter )
					error( "incorrect type" );
				if( symbol_table.lookupType($1)->ident_type == TYPE_INT )
					if( $3->tp == TYPE_FLT )
						error( "incorrect assignment, integer expected" );
			}
		|
			WHILE expression DO_KEYWORD statement
		|
			WHILE expression error statement
			{
				if(debug)
					printf( "#statement#\n" );
				error( "'DO' expected" );
				yyerrok;
			}
		|
			REPEAT statement_list UNTIL expression
		|
			REPEAT statement_list error 
			{
				if(debug)
					printf( "#statement#\n" );
				error( "'UNTIL' expected" );
				yyerrok;
			}
		|
			IF expression THEN statement
		|
			IF expression error statement
			{
				if(debug)
					printf( "#statement\n#" );
				error( "'THEN' expected" );
			}
		|
			IF expression THEN statement ELSE statement
		|
			IF expression error statement ELSE statement
			{
				if(debug)
					printf( "#statement#\n" );
				error( "'THEN' expected" );
				yyerrok;
			}
		|
			compound_statement
		|
			error
			{
				error( "not a statement" );
				yyerrok;
				//yyclearin;
			}
	;

expression_list: 
			expression
			{
				$$ = new list<ExprAttr*>;
				$$->push_back( $1 );
			}
		|
			expression_list COMMA expression
			{
				$1->push_back( $3 );
				$$ = $1;		
			}
		|
			expression_list error expression
			{
				if(debug)
					printf( "#expression_list#\n" );
				error( "',' expected" );
				yyerrok;
			}
	;

expression: 
			simple_expression
			{
				
			}
		|
			simple_expression REL_OP simple_expression
	;

simple_expression: 
			term
			{
				$$->lval = $1->lval;
				$$->tp = $1->tp;
			}
		|
			ADD_OP term
		|
			simple_expression ADD_OP term
	;

term:
			factor
		|
			term MUL_OP factor
	;

factor: 
			IDENT
			{
				Entry* binding = symbol_table.lookupBinding( $1 );
				
				if(binding->getType()!=Entry::parameter || binding->getType()!=Entry::variable)
				{
					error( "illegal factor: variable or parameter expected" );
				}
				else
				{
					$$->tp = binding->getType();
					$$->lval = 1;
				}
			}
		|
			constant
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
		|
			STRING
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
		|
			FLOAT
	;

identifier_list:
			IDENT
			{
				$$ = new list<char*>();
				$$->push_back( $1 );
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
	fprintf( stderr, "Line %d: %s\n", yylineno, msg );
	fflush( stderr );
}
