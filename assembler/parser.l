/*-*-C-*-*/

%{ 
#include "yacc.tab.h"
#include <stdio.h>
#include <string.h>
%}

%%

[A-Za-z]+ { yylval.string = strdup(yytext); return STRING; }
[0-9]+ { yylval.number = atoi(yytext); return NUMBER; }
[ \t\r\n]+ {}
. { return yytext[0]; }

%%
void yyerror(char *message) {
	fprintf(stderr, "%s\n", message);
}
int yywrap(void) {
	return 1;
}
