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

int 
yywrap( void )
{
  return 1;
}
