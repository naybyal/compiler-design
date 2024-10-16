#include<stdio.h>

void main() {
    char input[10][10], s;
    int i,k,j;

    printf("Enter the expressions\n");
    for(i=0;i<5;i++) {
        scanf("%s",&input[i]);
    }
    
    for(k=0;k<5;k++) {
        s=input[k][3];
        switch(s) {
            case '*':
                printf("\nMOV R%d, %c \n",k,input[k][2]);
                printf("MUL R%d, %c \n",k,input[k][4]);
                printf("MOV %c ,R%d  \n",input[k][0],k);
                break;
            case '+':
                printf("\nMOV R%d, %c \n",k,input[k][2]);
                printf("ADD R%d, %c \n",k,input[k][4]);
                printf("MOV %c, R%d \n",input[k][0],k);
                break;
            case '-':
                printf("\nMOV R%d, %c \n",k,input[k][2]);
                printf("SUB R%d, %c \n",k,input[k][4]);
                printf("MOV %c, R%d \n",input[k][0],k);
                break;
            default:
                printf("\nexit");
                break;
        }
    }
}