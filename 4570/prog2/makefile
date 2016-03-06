all: first second third

first: upc.y
	yacc upc.y

second: upc.l
	flex upc.l

third: main.c
	gcc -o test lex.yy.c y.tab.c main.c -ll
