#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

int value(char x) {
    switch(x) {
        case 'i': 
            return 0;
        case '+':
            return 1;
        case '*':
            return 2;
        case '$':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        default:
            return 0;
    }
}

char precedenceMatrix[][6] = {
    {' ', '>', '>', '>', ' ', '>'},
    {'<', '>', '<', '>', '<', '>'},
    {'<', '>', '<', '>', '<', '>'},
    {'<', '<', '<', ' ', '<', ' '},
    {'<', '<', '<', ' ', '<', '='},
    {' ', '>', '>', '>', ' ', '>'}
};

void main() {
    int i = 0;
    char a, b, c;
    char inputString[100];
    printf("Enter the string: ");
    scanf("%s", inputString);

    stack[++top] = '$';
    int length = strlen(inputString);
    inputString[length] = '$';
    inputString[length + 1] = '\0';

    while (top != -1) {
         a = stack[top];
         b = inputString[i];
         c = precedenceMatrix[value(a)][value(b)];

         if (a == '$' && b == '$') {
            printf("The string is accepted!");
            break;
         } else if (c == '<' || c == '=') {
            push(c);
            push(b);
            i++;
         } else if (c == '>') {
            while (top != -1 && stack[top] != '<')  pop();
            if (stack[top] == '<')  pop();
         } else {
            printf("The string is not accepted.");
            break;
         }
    }
}