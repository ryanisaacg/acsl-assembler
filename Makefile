CFLAGS = -Wall -Wextra

all: assembler vm translator

assembler: parser/parser.l parser/parser.y
	flex -olex.c parser/parser.l
	bison -d -byacc parser/parser.y -v
	gcc lex.c yacc.tab.c $(CFLAGS) -o assembler

vm: machine/machine.c
	gcc machine/machine.c $(CFLAGS) -o vm

translator: machine/translator.c
	gcc machine/translator.c $(CFLAGS) -o translator
