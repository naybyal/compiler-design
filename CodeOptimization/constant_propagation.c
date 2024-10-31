/*
 * Program Name: Optimization bt Constant Propagation 
 * Author: Nabiel Ahammed
 * Description: 
 * This program performs optimization by constant propagation on a series of expressions. 
 * Constant propagation replaces variables with known constant values in subsequent 
 * expressions, allowing for code simplification and potential elimination of redundant 
 * expressions.
 * The input format for each expression is "op op1 op2 res", where:
 *    - op: operator (+, -, *, /, =)
 *    - op1 and op2: operands (variables or constants)
 *    - res: result variable
 * If an expression has constant operands, the computed result replaces any further 
 * usage of the original result variable in subsequent expressions.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void input();
void output();
void change(int p, char *res);
void constant();

struct expr {
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];

int n;

int main() {
    input();
    constant();
    output();
    return 0;
}

void input() {
    printf("\n\nEnter the number of expressions: ");
    scanf("%d", &n);

    printf("\nEnter the expressions (format: op op1 op2 res):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        arr[i].flag = 0;
    }
}

void constant() {
    for (int i = 0; i < n; i++) {
        // If both operands are digits or if the operator is '='
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0) {
            int op1 = atoi(arr[i].op1);
            int op2 = isdigit(arr[i].op2[0]) ? atoi(arr[i].op2) : 0; // Check if op2 is a digit
            int res;
            switch (arr[i].op[0]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op2 != 0 ? op1 / op2 : 0; break; // Handle division by zero
                case '=': res = op1; break;
                default: continue;
            }

            char resStr[5];
            sprintf(resStr, "%d", res);

            arr[i].flag = 1; // Mark the expression as eliminated
            change(i, resStr); // Update further expressions with the result
        }
    }
}

void change(int p, char *res) {
    for (int i = p + 1; i < n; i++) {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
            strcpy(arr[i].op1, res);
        if (strcmp(arr[p].res, arr[i].op2) == 0)
            strcpy(arr[i].op2, res);
    }
}

void output() {
    printf("\nOptimized code is:\n");
    for (int i = 0; i < n; i++) {
        if (!arr[i].flag) {
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}
