/* 
 * token declarations
 */

%{

#include <stdio.h>
#include <stdlib.h>

#define YYSTYPE double

extern int yylineno;

int yylex ( void );
int yyerror( char *msg );
void error( char *msg1, char *msg2 );


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
		{	
		  printf( "%f\n", $2 );
		}
	|   
	expr  EQUALS
		{	
		  printf( "%f\n", $1 );
		}
	|
	error EQUALS  /* the parser will skip until the next EQUALS sign */
		{
		  error( "Error in expression: ", "reenter" );
		}
	;

expr:   PLUS  factor
		{ $$ = $2; }
	|
	MINUS  factor
		{ $$ = -$2; }

	|
	expr   PLUS   term
		{ $$ = $1 + $3; }
	|
	expr   MINUS  term
		{ $$ = $1 - $3; }
	|
	term
		{ $$ = $1; }
	;

term:   term   TIMES  factor
		{ $$ = $1 * $3; }
	|
	term   DIVIDE  factor
		{ 
		  if ( $3 == 0 ) 
		    error( "Division by 0", "" );
		  else 
		    $$ = $1 / $3; 
		}
	|
	factor
		{ $$ = $1; }
	;

factor: FLOAT
		{ $$ = $1; }
	|
	LPAR  expr  RPAR
		{ $$ = $2; }
	;

%%

int
yyerror( char *msg )
{
  /*  silent yyerror  */
}

void
error( char *msg1, char *msg2 )
{
  fprintf( stderr, "Line %d: %s%s\n", yylineno, msg1, msg2 );
}
