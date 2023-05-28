
OBJ : lex.tab.o lex.yy.o pile.o tab_instru.o interpreteur.o Function_manager.o Jump_manager.o cross_compiler.o

all: lex
%.o: %.c
	gcc -c -Wall $< -o $@ 

lex.tab.c lex.tab.h:	lex.y 
	bison -t -v -d  $<
	

lex.yy.c: lex.l lex.tab.h 
	flex lex.l



lex: lex.tab.o lex.yy.o pile.o tab_instru.o interpreteur.o Function_manager.o Jump_manager.o cross_compiler.o
	gcc -o lex $^
	
	
clean:
	rm  lex lex.tab.c lex.yy.c lex.tab.h lex.output

test: all
	./lex < fichier.c
	python cross.py

