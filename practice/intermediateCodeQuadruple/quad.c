#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[1024];
int top = -1;

int isOperator(char x);
int getPriority(char x);

void push(char x);
char pop();

void main() {
    int i, length, k;
    char input[1024], postfix[1024], x, first, second, temp;

    push('$');
    printf("Enter the expression : ");
    scanf("%s", input);

    length = strlen(input);

    // handle unary minus
    for (i=0; i<length; i++) {
        if (input[i] == '-' && (i == 0 || isOperator(input[i - 1]))) {
            input[i] = '_';     // unary minus is denoted by '_'
        }
    }

    // converting to postfix notation
    k = 0;
    for (i=0; i<length; i++) {
        if (isOperator(input[i])) {
            if (top <= 0 || stack[top] == '(' || input[i] == '(') 
                push(input[i]);
            else if (input[i] == ')') {
                while ((x = pop()) != '(') 
                    postfix[k++] = x;
            }
            else if (getPriority(input[i]) < getPriority(stack[top])) 
                push(input[i]);
            else {
                postfix[k++] = pop();
                push(input[i]);
            }
        } else  
            postfix[k++] = input[i];
    }

    while ((x = pop()) != '$')
        postfix[k++] = x;
    postfix[k++] = '\0';

    printf("Postfix form : %s", postfix);
    printf("\n\nOperator\tArg1\tArg2\tRes\n");
    for (i=0, x='0'; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) 
            push(postfix[i]);
        else {
            if (postfix[i] == '_' || postfix[i] == '=') 
                second = '_';
            else 
                second = pop();

            first = pop();
        
            if (postfix[i] == '_') {
                printf("%s\t\t%c\t%c\t%c\n", "UMinus", first, second, x);
                push(x++);
            } else {
                if (postfix[i] == '=') {
                    temp = pop();
                    printf("%c\t\t%c\t%c\t%c\n", postfix[i], first, second, temp);
                } else {
                    printf("%c\t\t%c\t%c\t%c\n", postfix[i], first, second, x);
                    push(x++);
                }
            }
        }
    }

    printf("\n");
}

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top < 0) 
        return '$';
    else 
        return stack[top--];
}

int isOperator(char x) {
    switch (x) {
        case '(':
        case '_':
        case '^':
        case '%':
        case '/':
        case '*':
        case '+':
        case '-':
        case ')':
        case '=':
            return 1;
        default: 
            return 0;
    } 
}

int getPriority(char x) {
    switch (x) {
        case '(':
            return 0;
        case '_':
            return 1;
        case '^':
            return 2;
        case '%':
            return 3;
        case '/':
            return 4;
        case '*':
            return 5;
        case '+':
            return 6;
        case '-':
            return 7;
        case ')':
            return 8;
        case '=':
            return 9;
        case '$':
            return 10;
        default: 
            return 11;
    } 
}