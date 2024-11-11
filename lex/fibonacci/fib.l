%{
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    int a = 0, b = 1, next;

    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
%}

%%

[0-9]+  { 
            int n = atoi(yytext);  // Convert matched text to integer
            printFibonacci(n);    
        }

.       { /* Ignore any other characters */ }

%%

int main() {
    printf("Enter the number of terms for Fibonacci sequence:\n");
    yylex();  
    return 0;
}

int yywrap() {
    return 1;
}