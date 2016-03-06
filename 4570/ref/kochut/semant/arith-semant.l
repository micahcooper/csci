/*
Use the line:  

%option yylineno 
  

when compiling with flex

*/

%option yylineno 


%{

#define YYSTYPE double

#include "y.tab.h"

void fatal( char *, char * );
void error( char *, char * );

extern double yylval;
double atof(const char *);

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

{float}		{
  		  yylval = atof(yytext);
		  return FLOAT;
		}

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
