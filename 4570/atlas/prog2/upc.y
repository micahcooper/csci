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

%{

#include <stdio.h>

void yyerror( const char *msg );
void error( const char *msg );
int yylex( void );
extern int yylineno;
int debug = 0;

%}

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
		|	
			PROGRAM IDENT error
			{
				if(debug)
					printf( "program header\n" );
				error( "';' expected" );
				//yyclearin;
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
			PROCEDURE IDENT LPAR parameter_list RPAR SEMI
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
	;
parameter_list: 
			parameter_group
		|
			parameter_list SEMI parameter_group
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
			VAR identifier_list COLON IDENT
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

		|
			identifier_list COLON IDENT
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
		|
			IDENT LPAR expression_list RPAR
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
		|
			expression_list COMMA expression
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
		|
			simple_expression REL_OP simple_expression
	;

simple_expression: 
			term
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
				yyerrok;
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
		|
			identifier_list COMMA IDENT
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
