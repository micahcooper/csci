all: first second third fourth clean

first: upc.l 
	flex upc.l

second: first main.c
	gcc -c main.c lex.yy.c

third:
	gcc -o upc lex.yy.o main.o -ll

fourth:
	./upc sample1.p

clean:
	rm lex.yy.c lex.yy.o main.o
