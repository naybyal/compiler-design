/*
    Constructing DFA for the string (a+b)*bab(a+b)*
        

    STATE TRANSITION TABLE
    _____________________________
    | State | Input a | Input b |
    |-------|---------|---------|
    |  q0   |   q0    |   q1    |
    |  q1   |   q2    |   q1    |
    |  q2   |   q0    |   q3    |
    | [q3]  |   q3    |   q3    |
    -----------------------------


    Author  ->  Nabiel Ahammed
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int state;

void q0(char ch) {
    if (ch == 'a')  state = 0;
    else state = 1;
}

void q1(char ch) {
    if (ch == 'a')  state = 2;
    else state = 1;
}

void q2(char ch) {
    if (ch == 'a')  state = 0;
    else state = 3;
}

void q3(char ch) {
    if (ch == 'a' || ch == 'b') state = 3;
}

int isAccepted(char input[]) {
    int length = strlen(input);
    for (int i=0; i<length; i++) {
        if (state == 0) 
            q0(input[i]);
        else if (state == 1) 
            q1(input[i]);
        else if (state == 2)
            q2(input[i]);
        else if (state == 3) 
            q3(input[i]);
    }

    if (state == 3)
        return 1;
    else return 0;
}

void main() {
    char buffer[20];
    
    do {
        printf("Enter a string  ->  ");
        scanf("%s", buffer);

        state = 0;
        for (int i=0; i<strlen(buffer); i++) {
            if (buffer[i] != 'a' && buffer[i] != 'b') {
                printf("\nInvalid Input! Exiting...\n");
                exit(0);
            }
        } 

        if (isAccepted(buffer)) {
            printf("\nAccepted!\n");
        } else  printf("\nRejected. \n");
    } while(1);
}