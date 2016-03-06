all: first second fourth run

one: first second third script

two: first second third clean run2

first: upc.y
	yacc -d -v upc.y

second: upc.l
	flex upc.l

third: main.cpp Entry.h symtab.h
	g++ -o run testpgm.cpp symtab.cpp

fourth: Entry.h symtab.h
	g++ -o upc lex.yy.c y.tab.c main.cpp symtab.cpp -ll

clean: 
	rm lex.yy.c y.tab.c y.output

run:
	./upc sample1.p	

run2:
	./run 
