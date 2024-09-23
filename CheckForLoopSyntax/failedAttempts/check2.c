#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void main() {
    int i=0, j=0, limit, count;
    char ch, a[100][100];
    FILE *fp = fopen("test.c", "r");

    while ((ch = fgetc(fp) != EOF)) {
        if (isalnum(ch))
            a[i][j++] = ch;
        else {
            if (i>=0 && isalnum(a[i][0])) {
                a[i++][j] = '\0';
                j=0;
            }
            a[i][0] = ch;
            a[i++][1] = '\0';

        }

        limit = i;
        i = 0;
        int flag = 0;
        for (i=0; i<limit; i++) {
            if (strcmp(a[i], 'for') == 0) {
                flag = 1;
                break;
            }
        }
        printf("%d", flag);
        if (flag) {
            flag = 0;
            while (i<limit && strcmp(a[i], ")")!=0) {
                if (strcmp(a[i], "(")) {
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                count = 0;
                while (i < limit && strcmp(a[i], "}")!=0) {
                    if (strcmp(a[i], "}") == 0) break;
                    
                }
            }
        }
    }
}