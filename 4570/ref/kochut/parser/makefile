all: first second third

first:
	yacc gram-err.y

second: 
	flex gram-err.l

third:
	gcc -o test -DYYDEBUG lex.yy.c y.tab.c main.c -ll
