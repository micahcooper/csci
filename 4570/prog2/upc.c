%{
#include "y.tab.h"
%}

delim				[ \t\n]
ws					{delim}+
letter 				[a-zA-Z]
digit 				[0-9]
ident				{letter}({letter}|{digit})*
word				[a-zA-Z]+
number				{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
string_constant		(("'")({word}("'"))
add_op				(("+")|("-"))
mul_op				(("*")|("/")|("div"))
rel_op				(("<")|("<=")|("=")|("<>")|(">=")|(">"))
comment 			"{"[^}]*"}"	
semicolon			";"
lpar				((\()(" ")*(",")({lpar})(" ")+)
rpar				\)
program				({program_header}{block}".")
program_header		("program"(" ")+({ident})([ \t])*({semicolon}))
block				({declarations}{compound_stmt})
declarations		({declarations}{declaration})?
declaration			(("var")(" ")+({variable_decls})|{procedure_decl})
variable_decls		(({variable_decls})(" ")+({variable_decl})|({variable_decl}))
variable_decl		(({ident_list})(" ")+(":")(" ")+({ident})(" ")+(";"))
procedure_decl		(({procedure_header})({block})({semicolon}))
procedure_header	((("procedure")(" ")({ident})({lpar})(" ")*({param_list})(" ")*({rpar})(";")(" ")*(";"))|("procedure")(" ")+({ident})(" ")*(";"))
param_list			(({param_group})|(({param_list})(" ")*(";")(" ")*({param_group})))
param_group			((("var")(" ")+({ident_list})(" ")*(":")(" ")*({ident}))|({ident_list}(" ")*(":")(" ")({ident})))
compound_stmt		(("begin")(" ")+({stmt_list})(" ")+("end"))
stmt_list			(({stmt})|(({stmt_list})(" ")+)(";")(" ")+({stmt}))
stmt				(({ident})|(({ident})(" ")*({lpar})(" ")*({expr_list})(" ")*({rpar}))|(({ident})(" ")*(":=")(" ")*({expr}))|(("while")(" ")+({expr})(" ")+("do")(" ")+({stmt}))|(("repeat")(" ")+({stmt_list})(" ")+("until")(" ")+({expr}))|(("if")(" ")+({expr})(" ")+("then")(" ")+)({stmt})|(("if")(" ")+({expr})(" ")+("then")(" ")+({stmt})({ws})+("else")(" ")+({stmt}))|({compound_stmt}))
expr_list			(({expr})|((expr_list)(" ")+(",")(" ")+({expr})))
expr				(({simple_expr})|(({simple_expr})(" ")*({rel_op})(" ")*({simple_expr})))
simple_expr			(({term})|(({add_op})(" ")*({term}))|(({simple_expr})(" ")*({add_op})(" ")*({term})))
factor				(({ident})|({constant})|(({lpar})(" ")*({expr})(" ")*({rpar})))
term				(({factor})|(({term})(" ")*({mul_op})(" ")*({factor})))
constant			(({string_constant})|({number}))
ident_list			(({ident})|(({ident_list})(" ")*(",")(" ")*({ident})))


%%
{ident}				return IDENT;
{ws}				return IGNORE;
{semicolon}			return SEMICOLON;
{number}			return NUMBER;
{program_header}	return PROGRAM_HEADER;
{lpar}				return 0;
.					return ERROR;
%%
