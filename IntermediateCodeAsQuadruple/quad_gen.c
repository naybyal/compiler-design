/******************************************************************************
 * 
 * Program    : Print Intermediate Code to Quadruple
 * Author     : Nabiel Ahammed
 * Date       : September 24, 2024
 * 
 * Description:
 * This program takes intermediate code as input and prints its corresponding 
 * quadruple representation. Quadruples consist of an operator and up to three 
 * operands and are used during compiler optimization stages.
 * 
 * Functionality:
 * - Converts an infix expression to postfix (Reverse Polish Notation).
 * - Parses postfix expression to generate quadruples.
 * 
 * Example Input:
 *      t1 = a + b
 *      t2 = t1 * c
 * 
 * Example Output:
 *      ( + , a , b , t1 )
 *      ( * , t1 , c , t2 )
 * 
 * Compilation:
 *      gcc -o quad_gen quad_gen.c
 * 
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char stack[100];
int top = -1;

int isOperator(char x);
int getPriority(char x);
void push(char x);
char pop();

int main() {
    int i, length, k;
    char inputString[100], postfixForm[100], x, first, second, temp;
    
    push('$');
    printf("Enter The Expression\t->\t");
    scanf("%s", inputString);
    
    length = strlen(inputString);
    
    // Handling unary minus
    for (i = 0; i < length; i++) {
        if (inputString[i] == '-' && (i == 0 || isOperator(inputString[i - 1]))) // If '-' comes first or comes before an operator
            inputString[i] = '_'; // Denoting unary minus by underscore
    }
    
    // Convert to postfix
    k = 0;
    for (i = 0; i < length; i++) {
        if (isOperator(inputString[i])) {
            if (top <= 0 || stack[top] == '(' || inputString[i] == '(')
                push(inputString[i]);
            else if (inputString[i] == ')') {
                while ((x = pop()) != '(')
                    postfixForm[k++] = x;
            } else if (getPriority(inputString[i]) < getPriority(stack[top]))
                push(inputString[i]);
            else {
                postfixForm[k++] = pop();
                push(inputString[i]);
            }
        } else {
            postfixForm[k++] = inputString[i];
        }
    }
    
    while ((x = pop()) != '$')
        postfixForm[k++] = x;
    
    postfixForm[k++] = '\0';
    
    printf("Postfix Form\t\t->\t%s\n", postfixForm);
    printf("\n\t---QUADRUPLES---\n");
    printf("\nOperator\tArg1\tArg2\tResult\n");
    for (i = 0, x = '0'; postfixForm[i] != '\0'; i++) {
        if (!isOperator(postfixForm[i])) {
            push(postfixForm[i]);
        } else {
            if (postfixForm[i] == '_' || postfixForm[i] == '=')
                second = '_';
            else
                second = pop();
            
            first = pop();
            
            if (postfixForm[i] == '_') {
                printf("%s\t\t%c\t%c\t%c\n", "UMinus", first, second, x);
                push(x++);
            } else {
                if (postfixForm[i] == '=') {
                    temp = pop();
                    printf("%c\t\t%c\t%c\t%c\n", postfixForm[i], first, second, temp);
                } else {
                    printf("%c\t\t%c\t%c\t%c\n", postfixForm[i], first, second, x);
                    push(x++);
                }
            }
        }
    }
    printf("\n");
    return 0;
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
    switch(x) {
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

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top >= 0) 
        return stack[top--];
    else
        return '$'; 
    
}
