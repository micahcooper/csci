/* 
 * token declarations
 */

%{

#include <stdio.h>

int  yylex( void );
void yyerror( const char *msg );
void error( char *msg1, char *msg2 );

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

elines:	elines   eline   
	|   
	eline
	;

eline:	expr   EQUALS
	|
	error  EQUALS
		/* the parser willl skip until the next EQUALS character */ 
	{
	  error( "Error in expression: ", "reenter" );
	}
	;

expr:   expr   PLUS   term
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

factor: PLUS  factor
	|
	MINUS  factor
	|
	FLOAT
	|
	LPAR  expr  RPAR
	;

%%

void
yyerror( const char *msg )
{
  /*  silent yyerror  */
  /*
    printf("Line %d: %s\n", yylineno, msg);
  */
}

