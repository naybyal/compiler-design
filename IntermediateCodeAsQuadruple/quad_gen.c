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

#define MAX 100

char stack[MAX];
int top = -1;

int is_operator(char x);
int precedence(char x);
void push(char x);
char pop();

int main() {
    int i, k = 0;
    char expression[MAX], postfix[MAX], x;
    
    // Initialize stack with sentinel '$'
    push('$');
    
    printf("Enter the expression:\n");
    fgets(expression, MAX, stdin);
    
    int len = strlen(expression);
    
    // Replace unary minus with '_'
    for (i = 0; i < len; i++) {
        if (expression[i] == '-' && (i == 0 || is_operator(expression[i - 1]))) {
            expression[i] = '_'; // Unary minus marked as '_'
        }
    }
    
    // Convert infix to postfix
    for (i = 0; i < len; i++) {
        if (is_operator(expression[i])) {
            if (top <= 0 || stack[top] == '(' || expression[i] == '(') {
                push(expression[i]);
            } else if (expression[i] == ')') {
                while ((x = pop()) != '(') {
                    postfix[k++] = x;
                }
            } else if (precedence(expression[i]) > precedence(stack[top])) {
                push(expression[i]);
            } else {
                postfix[k++] = pop();
                push(expression[i]);
            }
        } else {
            postfix[k++] = expression[i];
        }
    }
    
    while ((x = pop()) != '$') {
        postfix[k++] = x;
    }
    
    postfix[k] = '\0';  
    
    // Display the postfix expression
    printf("Postfix Form:\n%s\n", postfix);
    
    // Evaluate the postfix expression
    printf("Quadruple Representation:\n");
    printf("Operator\tArg1\tArg2\tResult\n");
    char first, second, result = 't';
    
    for (i = 0; postfix[i] != '\0'; i++) {
        if (!is_operator(postfix[i])) {
            push(postfix[i]); // Push operands to stack
        } else {
            second = pop();  // Pop second operand
            first = pop();   // Pop first operand

            if (postfix[i] == '=') {
                printf("%c\t\t%c\t\t%c", postfix[i], first, second);
            } else {
                printf("%c\t\t%c\t%c\t%c", postfix[i], first, second, result);
                push(result++); 
            }

            printf("\n");
        }
    }

    return 0;
}

int is_operator(char x) {
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

int precedence(char x) {
    switch (x) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        case '=': return 0;
        default: return -1;
    }
}

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        return '$';  // Return sentinel if stack is empty
    }
}
