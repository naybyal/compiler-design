%{

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

%}


%%

[a-zA-Z]* {
    for (int i = 0; i < yyleng; i++) {
        yytext[i] = toupper(yytext[i]);
    }
    printf("\n%s\n", yytext);
}

[\t]* {
    return 1;
}

.* {
    ECHO;
}

\n {
    printf("\n%s\n", yytext);
}

%%

/*** C Code section ***/
int main(void) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}