#include <stdio.h>
#include <string.h>

int state = 0;

void q0(char value) {
    if (value == '0') {
        state = 2;
    } else if (value == '1') {
        state = 0;
    }
}

void q2(char value) {
    if (value == '0') 
        state = 2;
    else if  (value == '1') {
        state = 1;
    }
} 

void q1(char value) {
    if (value == '0' || value == '1') 
        state = 1;
}



void main() {
    char input[256];
    printf("Enter the string : ");
    scanf("%s", input);
    for (int i=0; i<strlen(input); i++) {
        if (state == 0) {
            q0(input[i]);
        } else if (state == 1) {
            q1(input[i]);
        } else if (state == 2) {
            q2(input[i]);
        }
    }

    if (state == 1) 
        printf("\nThe string has been accepted by the DFA\n\n");
    else    printf("\nThe string has been rejected by the DFA\n\n");
}