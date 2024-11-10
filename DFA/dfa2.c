#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    A   ->   state 0
    B   ->   state 1
    C   ->   state 2
*/

int state;
char buffer[1024];

void A(char ch);
void B(char ch);
void C(char ch);


int main() {
    printf("Enter the string : ");
    scanf("%s", buffer);

    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] != '0' && buffer[i] != '1') {
            printf("\nInvalid input.\n");
            exit(0);
        }
    }
    state = 0;
    int isAccepted = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        switch(state) {
            case 0:
                A(buffer[i]);
                break;
            case 1:
                B(buffer[i]);
                break;
            case 2:
                C(buffer[i]);
                break;
            default:
                break;
        }
    }

    if (state == 2)
        isAccepted = 1;

    if (isAccepted) {
        printf("\nThe string has been ACCEPTED by the DFA\n");
    } else {
        printf("\nThe string has been REJECTED by the DFA\n");
    }
}

void A(char ch) {
    if (ch == '0') {
        state = 0;
    } else if (ch == '1') {
        state = 1;       
    }
}

void B(char ch) {
    if (ch == '0') {
        state = 2;
    } else if (ch == '1') {
        state = 1;
    }
}

void C(char ch) {
    if (ch == '0') {
        state = 0;
    } else if (ch == '1') {
        state = 1;
    }
}