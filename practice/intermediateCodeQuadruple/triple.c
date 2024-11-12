#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top = -1;
char stack[1024];

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top >= 0) return stack[top--];
    else return '$';
}

int isOperator(char ch) {
    switch(ch) {
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

int getPriority(char ch) {
    switch(ch) {
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

int main() {
    char input[1024], postfix[1024];
    int i, k, length;
    char temp, reg, first, second;

    printf("Enter the infix string : ");
    scanf("%s", input);
    push('$');
    length = strlen(input);

    for (i=0; i<length; i++) {
        if (input[i] == '-' && (i == 0 || isOperator(input[i-1])))
            input[i] = '_';
    }
    
    //  convert infix to postfix
    k = 0;
    for (i = 0; i<length; i++) {
        if (!isOperator(input[i])) {
            postfix[k++] = input[i];
        } else {
            if (top <= 0 || stack[top] == '(' || input[i] == '(') {
                push(input[i]);
            } else if (input[i] == ')') {
                while ((temp = pop()) != '(') {
                    postfix[k++] = temp;
                }
            } else if (input[i] == '_') {
                postfix[k++] = input[i];
            } else if (getPriority(stack[top]) > getPriority(input[i])) {
                push(input[i]);
            } else {
                postfix[k++] = pop();
                push(input[i]);
            }
        }
    } 

    while ((temp = pop()) != '$') {
        postfix[k++] = temp;
    }

    postfix[k++] = '\0';
    printf("Postfix : %s", postfix);
    // print triples
    printf("\nTriples:\n");
    for (i = 0; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) {
            push(postfix[i]);
        } else {
            if (postfix[i] == '_') {
                second = pop();
                printf("UMinus\t_\t%c\n", second);
                push(second);
            } else if (postfix[i] == '=') {
                second = pop();
                first = pop();
                if (first == '$')
                    first = '_';
                printf("=\t%c\t%c\n", first, second);
            } else {
                second = pop();
                first = pop();
                printf("%c\t%c\t%c\n", postfix[i], first, second);
            }
        }
    }

    return 0;
}