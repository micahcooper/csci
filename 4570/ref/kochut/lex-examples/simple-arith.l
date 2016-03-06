/*
Use the line:  

%option yylineno 
  

when compiling with flex

*/

%option yylineno 

%{

#include "y.tab.h"

void fatal( char *, char * );
void error( char *, char * );

%}

float	[0-9]+("."[0-9]+)?
plus	\+
minus	\-
times	\*
divide	\/
equals	=
lpar	\(
rpar	\)
ws	[ \n\t\r]

%%

{float}		return FLOAT;

{plus}		return PLUS;

{minus}		return MINUS;

{times}		return TIMES;

{divide}	return DIVIDE;

{equals}	return EQUALS;

{lpar}		return LPAR;

{rpar}		return RPAR;

{ws}		;

. 		{ error( "Illegal input: ", yytext ); }

%%

void 
fatal( char *msg1, char *msg2 )
{
  printf( "%s%s\n", msg1, msg2 );
  exit(1);
}


void
error( char *msg1, char *msg2 )
{
  printf( "Line %d: %s%s\n", yylineno, msg1, msg2 );
}

int 
yywrap( void )
{
  return 1;
}

int
main( int argc, char **argv )
{
  int tok;

  if ( argc > 1 ) {

    yyin = fopen( argv[1], "r" );

    if ( yyin == NULL )
      fatal( argv[0], "cannot open input file" );
  }

  while( tok = yylex() )
    printf( "Next token: %d\n", tok );

  return 0;
}
