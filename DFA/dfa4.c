#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int state;
char buffer[1024];

void A(char ch);    // state 0
void B(char ch);    // state 1
void C(char ch);    // state 2  (final)
void D(char ch);    // state 3  (final)
void E(char ch);    // state -1 or Dead State

int main() {
    state = 0;
    printf("Enter the string : ");
    scanf("%s", buffer);

    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] != 'a' && buffer[i] != 'b') {
            printf("Invalid input\n");
            return 1;
        }
    }

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
            case 3:
                D(buffer[i]);
                break;
            case -1:
                E(buffer[i]);
                break;
            default:
                break;
        }
    }

    if (state == 2 || state == 3) 
        isAccepted = 1;
    

    if (isAccepted) 
        printf("\nThe string has been ACCEPTED by the DFA!\n");
    else 
        printf("\nThe string has been REJECTED by the DFA.\n");
    return 0;
}

void A(char ch) {
    if (ch == 'a') 
        state = 1;
    else if (ch == 'b')
        state = -1;
}

void B(char ch) {
    if (ch == 'a') 
        state = -1;
    else if (ch == 'b')
        state = 2;
}

void C(char ch) {
    if (ch == 'a')
        state = 3;
    else if (ch == 'b')
        state = 2; 
}

void D(char ch) {
    if (ch == 'a' || ch == 'b') 
        state = -1;
}

void E(char ch) {
    state = -1;
}
