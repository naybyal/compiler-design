%{
#include "y.tab.h"

%}

%%

"for"            { return FOR; }
"("              { return LPAREN; }
")"              { return RPAREN; }
";"              { return SEMICOLON; }
"{"              { return LBRACE; }
"}"              { return RBRACE; }
[a-zA-Z][a-zA-Z0-9]*  { return IDENTIFIER; }
"="              { return ASSIGNMENT; }
[0-9]+           { return NUMBER; }
[ \t\n]+         ; // Ignore whitespace
.                { printf("Unexpected character: %s\n", yytext); }

%%

int yywrap() { return 1; } 