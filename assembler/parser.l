/*-*-C-*-*/

%{ 
#include "yacc.tab.h"
%}

%%

[A-Za-z]+ { yylval.string = strdup(yytext); return STRING; }
[0-9]+ { yylval.number = atoi(yytext); return NUMBER; }
"\n" { return LINE_END; }
. { return yytext[0]; }

%%
void yyerror(char *message) {
	fprintf(stderr, "%s at line %d", message, yylineno);
}
int yywrap(void) {
	return 1;
}
