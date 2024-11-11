#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int n;

struct expr {
    //  quadruple
    char op[2], op1[5], op2[5], res[5];
    //  flag to mark the expression as eliminated or not
    int flag
} arr[32];


void input();
void mutate(int p, char *res);
void constantPropagation();
void output(); 

int main() {
    input();
    constantPropagation();
    output();

    return 0;
}

void input() {
    // read the quadruples
    printf("Enter the number of expressions : ");
    scanf("%d", &n);

    printf("\nEnter the expressions (format: op op1 op2 res):\n");
    for (int i = 0; i<n; i++) {
        scanf("%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        arr[i].flag = 0;    // initially mark it as uneliminated
    }
}

void output() {
    printf("\nThe optimized code is as follows :\n");
    for (int i = 0; i < n; i++) {
        if (!arr[i].flag) {
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}

void mutate(int p, char *res) {
    for (int i = p + 1; i < n; i++) {
        
        if (strcmp(arr[p].res, arr[i].op1) == 0) {
            strcpy(arr[i].op1, res);
        }

        if (strcmp(arr[p].res, arr[i].op2) == 0) {
            strcpy(arr[i].op2, res);
        }

    }
}

void constantPropagation() {
    for (int i = 0; i < n; i++) {
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0) {
            int op1 = atoi(arr[i].op1);
            int op2 = atoi(arr[i].op2);
            int res;

            switch(arr[i].op[0]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op2 != 0 ? (op1 / op2) : 0;
                    break;
                default:
                    continue;
            }

            char resStr[5];
            sprintf(resStr, "%d", res);
            arr[i].flag = 1;
            change(i, resStr);
        }
    }
}