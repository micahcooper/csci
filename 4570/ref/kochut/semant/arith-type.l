/*
Use the line:  

%option yylineno 
  

when compiling with flex

*/

%option yylineno 


%{

#include "value.h"
#define YYSTYPE val
#include "y.tab.h"

void fatal( char *, char * );
void error( char *, char * );


double atof(const char *);
int    atoi(const char *);

%}

int	[0-9]+
float	[0-9]+("."[0-9]+)
plus	\+
minus	\-
times	\*
divide	\/
equals	=
lpar	\(
rpar	\)
ws	[ \n\t\r]

%%

{int}		{
  		  yylval.type = INT;
  		  yylval.val.ival = atoi(yytext);
		  return INT;
		}

{float}		{
  		  yylval.type = FLOAT;
  		  yylval.val.dval = atof(yytext);
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
