%{
#include <stdio.h>
#include <stdlib.h>

// Function to handle errors
void yyerror(const char *s);
int yylex();
%}

// Tokens from the lexical analyzer
%token FOR LPAREN RPAREN SEMICOLON LBRACE RBRACE IDENTIFIER ASSIGNMENT NUMBER

%%
program:
    statement
;

statement:
    for_loop
;

for_loop:
    FOR LPAREN initialization SEMICOLON condition SEMICOLON increment RPAREN LBRACE block RBRACE
    {
        printf("Valid 'for' loop syntax\n");
    }
;

initialization:
    IDENTIFIER ASSIGNMENT NUMBER
;

condition:
    IDENTIFIER
;

increment:
    IDENTIFIER
;

block:
    /* Assuming block can be empty or have statements */
    /* Add production rules for any block statement if needed */
    /* For simplicity, we assume the body is empty here */
    /* You could add more rules for statements inside the block */
    /* block : statement | statement block */
    /* Leaving it empty for the sake of example */
;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter a 'for' loop to check its syntax:\n");
    if (yyparse() == 0) {
        printf("Syntax analysis completed successfully.\n");
    } else {
        printf("Syntax analysis failed.\n");
    }
    return 0;
}
