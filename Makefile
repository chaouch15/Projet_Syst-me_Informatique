all: lex

lex.tab.c lex.tab.h:	lex.y
	bison -t -v -d  lex.y
	

lex.yy.c: lex.l lex.tab.h
	flex lex.l

lex: lex.yy.c lex.tab.c lex.tab.h
	gcc -g -o lex lex.tab.c lex.yy.c

clean:
	rm lex lex.tab.c lex.yy.c lex.tab.h lex.output

test: all
	./lex < fichier.c

