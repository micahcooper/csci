all: first second fourth clean

debug: first second third 

two: first second third clean run2

first:
	yacc -d -v upc.y

second:
	flex upc.l

third:
	g++ -o upc -DYYDEBUG lex.yy.c y.tab.c main.cpp symtab.cpp -ll

fourth:
	g++ -g -o upc lex.yy.c y.tab.c main.cpp symtab.cpp -ll

clean: 
	rm lex.yy.c y.tab.c y.output y.tab.h

run:
	./upc sample1.p	

run2:
	./run 
