%{
#include <stdio.h>
#include <stdlib.h>

// Declare the function yylex() which is defined in the lexer
extern int yylex();

// Declare a variable to store the result of the expression
int result; 

// Error handling function
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
%}

%union {
    int num;  // Semantic value for numbers
}

%token <num> NUMBER
%token PLUS MINUS MUL DIV LPAREN RPAREN

%type <num> expression term factor

%%

// Grammar rules
expression:
      expression PLUS term        { result = $1 + $3; }
    | expression MINUS term       { result = $1 - $3; }
    | term                        { result = $1; }
    ;

term:
      term MUL factor              { result = $1 * $3; }
    | term DIV factor              { if ($3 == 0) { yyerror("Division by zero!"); exit(1); } else { result = $1 / $3; } }
    | factor                       { result = $1; }
    ;

factor:
      NUMBER                       { result = yylval.num; }
    | LPAREN expression RPAREN     { result = $2; }
    ;

%%

// Main function to interact with the user
int main() {
    printf("Enter an expression: ");
    while (1) {
        if (yyparse() == 0) {  // Parse input and check for errors
            printf("Result: %d\n", result);  // Print the result after the expression is parsed
        }
        printf("Enter an expression: ");  // Prompt for the next input
    }
    return 0;
}

