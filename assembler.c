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

typedef unsigned char byte;
byte commands[4096][3];
byte variables[27];
byte box;

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
			box = variables[argument = 'A'];
			break;
		case STORE:
			variables[argument - 'A'] = box;
			break;
		case LABEL:
			break;
		case ADD:	
			box += variables[argument = 'A'];
			break;
		case ADD:	
			box += variables[argument = 'A'];
			break;
		case ADD:	
			box += variables[argument = 'A'];
			break;
		case ADD:	
			box += variables[argument = 'A'];
			break;
	}
	return i;
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
		for(size_t i = 0; i < command_index; i++) {
			i = execute_command(i);
		}
	}
	return 0;
}


