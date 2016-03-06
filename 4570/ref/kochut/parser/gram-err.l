/* gram-err.l
Use the line:  

%option yylineno 
  

when compiling with flex

*/



%{
#include "y.tab.h"
%}

%%
a	return A;
b	return B;
c	return C;
d	return D;
e	return E;
\n	;
.  	{ printf( "Illegal char in input: %s\n", yytext ); }
