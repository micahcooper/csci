/* 
 * token declarations
 */
%{

#include <stdio.h>

void free(void *ptr);
void yyerror( const char *msg );
int yylex( void );

extern int yylineno;

%}

%token  FLOAT
%token  PLUS
%token  MINUS
%token  TIMES
%token  DIVIDE
%token  EQUALS
%token  LPAR
%token  RPAR

%%

eseq:	eseq   expr  EQUALS
	|   
	expr  EQUALS
	;

expr:   PLUS   term
	|
	MINUS  term
        |
        expr   PLUS   term
	|
	expr   MINUS  term
	|
	term
	;

term:   term   TIMES  factor
	|
	term   DIVIDE  factor
	|
	factor
	;

factor: FLOAT
	|
	LPAR  expr  RPAR
	;

%%
void
yyerror( const char *msg )
{
  printf("Line %d: %s\n", yylineno, msg);
}


