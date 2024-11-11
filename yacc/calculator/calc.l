%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"  // Include the YACC header to access token definitions

extern YYSTYPE yylval;  // Use YYSTYPE for yylval
%}

%option noyywrap

%%

[0-9]+            { yylval.num = atoi(yytext); return NUMBER; }
"+"               { return PLUS; }
"-"               { return MINUS; }
"*"               { return MUL; }
"/"               { return DIV; }
"("               { return LPAREN; }
")"               { return RPAREN; }
[ \t\n]           { /* ignore whitespace */ }

%%
