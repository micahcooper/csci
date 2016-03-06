%{
#include "y.tab.h"

int lineno = 2;
%}
newline			[\n]
delim			[ \t]
ws				{delim}+
letter 			[a-zA-Z]
digit 			[0-9]
exp				(("e"|"E")({add_op}?)({unsigned_int}|{unsigned_int}))
ident			(({letter})|({letter}({letter}|{digit})*))
unsigned_int	(({digit})({digit}*))
num_error		({digit}+([a-df-zA-DF-Z])([a-zA-Z]*))
float			((({unsigned_int})(".")({unsigned_int}))({ws}|{semicolon})|(({unsigned_int})(".")({unsigned_int})({exp})))
string_constant	('([^'\n]|'')+')
comment 		(("{"[^}]*"}")|("(*"([^*]|"*"+[^*)])*"*"+")"))	
semicolon		";"
comma			","
colon			":"
lpar			\(
rpar			\)
program			([pP][rR][oO][gG][rR][aA][mM])
var				([vV][aA][rR])
add_op			(("+")|("-"))
mul_op			(("*")|("/")|("div"))
rel_op			(("<")|("<=")|("=")|("<>")|(">=")|(">"))
assign_op		(":=")
procedure		([pP][rR][oO][cC][eE][dD][uU][rR][eE])
begin			([bB][eE][gG][iI][nN])
if				([iI][fF])
while			([wW][hH][iI][lL][eE])
repeat			([rR][eE][pP][eE][aA][tT])
until			([uU][nN][tT][iI][lL])
then			([tT][hH][eE][nN])
else			([eE][lL][sS][eE])
eof				(({end})({ws})*("."))
end				([eE][nN][dD])
do				([dD][oO]))

%%
{newline}			{lineno++;}
{ws}				return IGNORE;
{semicolon} 		return SEMI;
{comma}				return IGNORE;
{colon}				return IGNORE;
{exp}				return EXP;
{unsigned_int}		return UNSIGNED_INT;
{float}				return FLOAT;
{lpar}				return LPAR;
{rpar}				return RPAR;
{add_op}			return ADD_OP;
{mul_op}			return MUL_OP;
{rel_op}			return REL_OP;
{assign_op}			return ASSIGN_OP;
{string_constant}	return STRING;
{comment}			return IGNORE;
{program} 			return PROGRAM;
{procedure}			return PROCEDURE;
{var}				return VAR;
{begin}				return BGN;
{if}				return IF;
{while}				return WHILE;
{repeat}			return REPEAT;
{until}				return UNTIL;
{then}				return THEN;
{else}				return ELSE;
{end}				return END;
{ident}				return IDENT;
{eof}				return PROGRAM_END;
{num_error}			return ERROR;
.					return ERROR;
%%
