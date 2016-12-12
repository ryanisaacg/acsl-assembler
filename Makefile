CFLAGS = -Wall -Wextra

all: asm vm translator

run: vm assembled
	./vm assembled

assembled: asm program
	./asm program assembled

asm: assembler/parser.l assembler/parser.y
	flex -olex.c assembler/parser.l
	bison -d -byacc assembler/parser.y -v
	gcc lex.c yacc.tab.c -Wno-implicit-function-declaration -o asm

vm: machine/machine.c
	gcc machine/machine.c $(CFLAGS) -o vm

translator: machine/translator.c
	gcc machine/translator.c $(CFLAGS) -o translator
