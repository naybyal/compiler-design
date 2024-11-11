%{
#include <stdio.h>
#include <stdlib.h>

void printFactorial(int n) {
    int originalNumber = n;
    int fact = 1;
    while (n != 1) {
        fact *= n--;
    }

    printf("\nThe factorial of %d is %d", originalNumber, fact);
}
%}

%%

[0-9]+ {
    int n = atoi(yytext);
    printFactorial(n);
}


. { /* ignore everything else */ }

%%

int main() {
    printf("Enter the number : ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}