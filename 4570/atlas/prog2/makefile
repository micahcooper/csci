all: first second fourth clean

one: first second third script

two: first second fourth script

first: upc.y
	yacc -d -v upc.y

second: upc.l
	flex upc.l

third: main.c
	gcc -o upc -DYYDEBUG lex.yy.c y.tab.c main.c -ll

fourth: main.c
	gcc -o upc lex.yy.c y.tab.c main.c -ll

clean: 
	rm lex.yy.c y.tab.c y.output

script:
	tsch test.csh
