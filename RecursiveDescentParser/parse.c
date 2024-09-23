/*
    RDP for the following grammar

    E   ->  TE'
    E'  ->  +TE'/null
    T   ->  FT'
    T'  ->  *FT'/null
    F   ->  (E)/id

    Author : Nabiel Ahammed
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int i, error;
char input[128];

void E() {
    T();
    EPrime();
}

void EPrime() {
    if (input[i] == '+') {
        i++;
        T();
        EPrime();
    }
}

void T() {
    F();
    TPrime();
}

void TPrime() {
    if (input[i] == '*') {
        i++;
        F();
        TPrime();
    }
}

void F() {
    if (isalnum(input[i])) {
        i++;
    } else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')')    i++;
        else error = 1;
    } else  error = 1;
}

void main() {
    i = 0; error = 0;
    printf("Enter the string    ->  ");
    scanf("%s", input);
    E();
    if (i == strlen(input) && error == 0) {
        printf("The string has been accepted! :)\n");
    } else {
        printf("The string has been rejected. :(\n");
    }
}

