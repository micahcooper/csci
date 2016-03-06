%option yylineno

%{
#include "y.tab.h"


%}
newline			[\n]
ws				[ \t]+
letter 			[a-zA-Z]
digit 			[0-9]
exp				(("e"|"E")({add_op}?)({unsigned_int}|{unsigned_int}))
ident			(({letter})|({letter}({letter}|{digit})*))
unsigned_int	(({digit})({digit}*))
num_error		({digit}+([a-df-zA-DF-Z])([a-zA-Z]*))
float			((({unsigned_int})(".")({unsigned_int}))({ws}|{semicolon})|(({unsigned_int})(".")({unsigned_int})({exp})))
string_constant	'([^'\n]|'')+'
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
end				([eE][nN][dD])
eof				(([^0-9]|{ws}*)(".")([^0-9]))
do				([dD][oO])

%%
{newline}			return NEWLINE;
{ws}				return IGNORE;
{semicolon} 		return SEMI;
{comma}				return COMMA;
{colon}				return COLON;
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
{comment}			;
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
{do}				return DO;
{eof}				return PROGRAM_END;
{num_error}			return NUM_ERROR;
.					return ERROR;
%%
