/*
    RDP for the following grammar

    E   ->  TE'
    E'  ->  +TE' | -TE' | NULL
    T   ->  FT'
    T'  ->  /FT' | NULL
    F   ->  (E) | id

    Author  :   Nabiel Ahammed
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char buffer[1024];
int i, error;

void E();
void EDash();
void T();
void TDash();
void F();

int main() {

    printf("Enter the string : ");
    scanf("%s", buffer);

    i = 0; error = 0;
    
    E();

    if (i == strlen(buffer) && !error) {
        printf("Parsing SUCCESSFUL!\n");
    } else {
        printf("Parsing FAILED.\n");
    }

    return 0;
}

void E() {
    T();
    EDash();
}

void EDash() {
    if (buffer[i] == '+') {
        i++;
        T();
        EDash();
    } else if (buffer[i] == '-') {
        i++;
        T();
        EDash();
    }
}

void T() {
    F();
    TDash();
}

void TDash() {
    if (buffer[i] == '/') {
        i++;
        F();
        TDash();
    }
}

void F() {
    if (buffer[i] == '(') {
        i++;
        E();
        if (buffer[i] == ')') {
            i++;
        } else {
            error = 1;
        }
    } else if (isalnum(buffer[i])) {
        i++;
    } else {
        error = 1;
    }
}

/*
     E   ->  TE'
    E'  ->  +TE' | -TE' | NULL
    T   ->  FT'
    T'  ->  /FT' | NULL
    F   ->  (E) | id
*/