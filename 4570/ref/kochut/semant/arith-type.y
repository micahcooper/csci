/* 
 * token declarations
 */

%{

#include <stdio.h>
#include <stdlib.h>

#include "value.h"

#define YYSTYPE val


extern int yylineno;

int yylex ( void );
int yyerror( char *msg );
void error( char *msg1, char *msg2 );


%}


%token  INT
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
		  if( $2.type == INT ) {
		    printf( "INT value: %d\n", $2.val.ival );
		  }
		  else if( $2.type == FLOAT ) {
		    printf( "FLOAT value: %f\n", $2.val.dval );
		  }
		  else
		    error( "Unknown type", "" );
		}
	|   
	expr  EQUALS
		{	
		  if( $1.type == INT ) {
		    printf( "INT value: %d\n", $1.val.ival );
		  }
		  else if( $1.type == FLOAT ) {
		    printf( "FLOAT value: %f\n", $1.val.dval );
		  }
		  else
		    error( "Unknown type", "" );
		}
	|
	error EQUALS  /* the parser will skip until the next EQUALS sign */
		{
		  error( "Error in expression: ", "reenter" );
		}
	;

expr:   PLUS  factor
		{ 
		  $$ = $2;
		}
	|
	MINUS  factor
		{
		  $$.type = $2.type; 
		  if( $2.type == INT )
		    $$.val.ival = - $2.val.ival;
		  else
		    $$.val.dval = - $2.val.dval;
		}
	|
	expr   PLUS   term
		{ 
		  if( $1.type == INT && $3.type == INT ) {
		    $$.type = INT;
		    $$.val.ival = $1.val.ival + $3.val.ival; 
		  }
		  if( $1.type == INT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.ival + $3.val.dval; 
		  }
		  if( $1.type == FLOAT && $3.type == INT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval + $3.val.ival; 
		  }
		  if( $1.type == FLOAT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval + $3.val.dval; 
		  }
		}
	|
	expr   MINUS  term
		{ 
		  if( $1.type == INT && $3.type == INT ) {
		    $$.type = INT;
		    $$.val.ival = $1.val.ival - $3.val.ival; 
		  }
		  if( $1.type == INT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.ival - $3.val.dval; 
		  }
		  if( $1.type == FLOAT && $3.type == INT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval - $3.val.ival; 
		  }
		  if( $1.type == FLOAT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval - $3.val.dval; 
		  }
		}
	|
	term
		{ $$ = $1; }
	;

term:   term   TIMES  factor
		{ 
		  if( $1.type == INT && $3.type == INT ) {
		    $$.type = INT;
		    $$.val.ival = $1.val.ival * $3.val.ival; 
		  }
		  if( $1.type == INT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.ival * $3.val.dval; 
		  }
		  if( $1.type == FLOAT && $3.type == INT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval * $3.val.ival; 
		  }
		  if( $1.type == FLOAT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval * $3.val.dval; 
		  }
		}
	|
	term   DIVIDE  factor
		{ 
		  if ( $3.type == INT && $3.val.ival == 0 ||
		       $3.type == FLOAT && $3.val.dval == 0 ) 
		    error( "Division by 0", "" );
		  else if( $1.type == INT && $3.type == INT ) {
		    $$.type = INT;
		    $$.val.ival = $1.val.ival / $3.val.ival; 
		  }
		  if( $1.type == INT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.ival / $3.val.dval; 
		  }
		  if( $1.type == FLOAT && $3.type == INT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval / $3.val.ival; 
		  }
		  if( $1.type == FLOAT && $3.type == FLOAT ) {
		    $$.type = FLOAT;
		    $$.val.dval = $1.val.dval / $3.val.dval; 
		  }
		}
	|
	factor
		{ $$ = $1; }
	;

factor: 
	INT
		{ $$ = $1; }
	|
	FLOAT
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
