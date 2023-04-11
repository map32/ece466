CC = gcc
XX = flex
CFLAGS  = -g -Wall

program: ast.h ast.c helpers.h helpers.c symtab.h symtab.c parsing.tab.c lex.yy.c
	$(CC) $(CFLAGS) -o program ast.h ast.c helpers.h helpers.c symtab.h symtab.c parsing.tab.c lex.yy.c

parsing.tab.c: parsing.y
	bison -d parsing.y

lex.yy.c: lexx.l lexx.h
	$(XX) lexx.l