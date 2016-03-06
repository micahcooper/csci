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
%token DO
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

%{

#include <stdio.h>

void yyerror( const char *msg );
void error( const char *msg );
%}

%%
program:		
			program_header block "."
		|	
			program_header block error
	;		

program_header:
			PROGRAM IDENT SEMI
	;

block:	
			declarations compound_statement
	;

declarations: 
			declarations declaration 
		|
			epsilon
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
	;

procedure_decl: 
			procedure_header block SEMI
	;

procedure_header: 
			PROCEDURE IDENT LPAR parameter_list RPAR SEMI
		|
			PROCEDURE IDENT SEMI

parameter_list: 
			parameter_group
		|
			parameter_list SEMI parameter_group
	;

parameter_group: 
			VAR identifier_list COLON IDENT
		|
			identifier_list COLON IDENT
	;

compound_statement: 
			BGN statement_list END
	;

statement_list: 
				statement 
		|	
				statement_list SEMI statement
	;

statement: 
			epsilon
		|
			IDENT
		|
			IDENT LPAR expression_list RPAR
		|
			IDENT ASSIGN_OP expression
		|
			WHILE expression DO statement
		|
			REPEAT statement_list UNTIL expression
		|
			IF expression THEN statement
		|
			IF expression THEN statement ELSE statement
		|
			compound_statement
	;

expression_list: 
			expression
		|
			expression_list COMMA expression
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
	;

constant:
			STRING
		|
			number
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
	;

epsilon:
	;
%%

void yyerror( char* msg )
{
	//if( strcmp( msg, "syntax error" )
	//	printf( "Syntax Error in Line : %d : %s\n", yylineno, msg );
}
void error( const char *msg )
{
	fprintf( stderr, "Line %d: %s\m", yylineno, msg );
	fflush( stderr );
}
