#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int i, error;
char input[256];

void E();
void EPrime();
void T();
void TPrime();
void F();

void main() {
    i = 0, error = 0;
    printf("Enter the string : ");
    scanf("%s", input);
    
    E();

    if (i == strlen(input) && error == 0) 
        printf("\nThe string has been accepted.\n");
    else    
        printf("\nThe string has been rejected.\n");    
}

void E() {
    T(); EPrime();
}

void T() {
    F(); TPrime();
}

void EPrime() {
    if (input[i] == '+') {
        i++;
        T(); EPrime();
    }
}

void TPrime() {
    if (input[i] == '*') {
        i++;
        F(); TPrime();
    }
}

void F() {
    if (input[i] == '(') {
        i++;
        E();

        if (input[i] == ')')
            i++;
        else error = 1;
    } else if (isalnum(input[i])) {
        i++;
    } else  error = 1;
}
