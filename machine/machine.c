#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Command Format:
[Command Code][Variable Name | =][Number if equals]
*/
#define DECLARE 0
#define LOAD 1
#define STORE 2
#define LABEL 3
#define ADD 4
#define SUBTRACT 5
#define MULTIPLY 6
#define DIVIDE 7
#define BRANCH_LESS 8
#define BRANCH_EQUAL 9
#define BRANCH_GREATER 10
#define BRANCH_UNCONDITIONALLY 11
#define PRINT 12
#define END 13

typedef unsigned char byte;
byte commands[4096][3];
int variables[27];
int box;
size_t num_commands;

size_t branch(byte label) {
	size_t i;
	for(i = 0; i < num_commands; i++) {
		if(commands[i][0] == LABEL && commands[i][1] == label)
			return i;
	}
	fprintf(stderr, "Jump failed to find label.");
	exit(-1);
}

size_t execute_command(size_t i) {
	byte command[3];
	memcpy(command, commands + i, 3);
	byte code 		= command[0];
	byte argument 	= command[1];
	byte value		= command[2];
	if(argument == '=') {
		argument = 'A' + 26;
		variables[26] = value;
	}
	switch(code) {
		case DECLARE:
			variables[argument - 'A'] = value;
			break;
		case LOAD:
			box = variables[argument - 'A'];
			break;
		case STORE:
			variables[argument - 'A'] = box;
			break;
		case LABEL:
			break;
		case ADD:	
			box += variables[argument - 'A'];
			break;
		case SUBTRACT:	
			box -= variables[argument - 'A'];
			break;
		case MULTIPLY:	
			box *= variables[argument - 'A'];
			break;
		case DIVIDE:	
			box /= variables[argument - 'A'];
			break;
		case BRANCH_LESS:
			if(box < 0)
				return branch(argument);
			break;
		case BRANCH_EQUAL:
			if(box == 0)
				return branch(argument);
			break;
		case BRANCH_GREATER:
			if(box > 0)
				return branch(argument);
			break;
		case BRANCH_UNCONDITIONALLY:
			return branch(argument);
		case PRINT:
			printf("%d\n", box);
			break;
		case END:
			exit(0);
			break;
	}
	return i + 1;
}

int main(int argc, char *argv[]) {
	if(argc <= 1) {
		puts("Please enter a filename.");
	} else {
		FILE* binary 		 = fopen(argv[1], "r");
		size_t command_index = 0;
		while(!feof(binary)) {
			commands[command_index][0] = fgetc(binary);
			commands[command_index][1] = fgetc(binary);
			commands[command_index][2] = fgetc(binary);
			command_index++;
		}
		num_commands = command_index;
		size_t i = 0;
		while(i < command_index) {
			i = execute_command(i);
		}
	}
	return 0;
}


