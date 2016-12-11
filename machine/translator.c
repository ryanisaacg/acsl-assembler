#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc < 3) {
		printf("Please enter an input file and an output file.");
	} else {
		FILE* input  = fopen(argv[1], "r");
		FILE* output = fopen(argv[2], "w");
		char byte[3];
		while(!feof(input)) {
			fgets(byte, 3, input);
			if(byte[0] == '\n' || byte[0] == '\r')
				continue;
			if(byte[1] == '\n' || byte[0] == '\r')
				byte[1] = '\0';
			int value = (int)strtol(byte, NULL, 16);
			fputc(value, output);
		}
		fclose(input);
		fclose(output);
	}
}
