/*
    Program :   for-loop Syntax Checker
    Author  :   Nabiel Ahammed
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main() {
    int i = 0, j = 0, limit, flag, count = 0;
    FILE *fp;
    char buffer[100][100], ch;

    fp = fopen("test.txt", "r");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch))
            buffer[i][j++] = ch;
        else {
            if (j > 0) {
                buffer[i][j] = '\0';
                j = 0;
                i++;
            }
            if (ch != ' ' && ch != '\n' && ch != '\t') {
                buffer[i][0] = ch;
                buffer[i++][1] = '\0';
            }
        }
    }

    fclose(fp); 
    limit = i;
    flag = 0;

    for (i=0; i<limit; i++) {
        if (strcmp(buffer[i], 'for') == 0) {
            flag = 1;
            break;
        }
        if (flag) {
            flag = 0;
            while (i < limit && strcmp(buffer[i], ')') != 0) {
                if (strcmp(buffer[i], '(') == 0) {
                    flag = 1;
                    break;
                }
                i++;
            }

            if (flag) {
                flag = 0;
                while (i < limit  && strcmp(buffer[i], ')') != 0) {
                    if (strcmp(buffer[i], ';') == 0) 
                        count++;
                    i++;
                }

                if (count == 2) {
                    flag = 0;
                    while (i < limit && strcmp(buffer[i], '{') != 0) {
                        if (strcmp(buffer[i], ')') == 0) {
                            flag = 1;
                            break;
                        }
                        i++;
                    }
                    if (flag) {
                        flag = 0;
                        while (i < limit && strcmp(buffer[i], '}') != 0) {
                            if (strcmp(buffer[i], '{') == 0) {
                                flag = 1;
                                break;
                            }
                            i++;
                        }
                        if (flag) {
                            flag = 0;
                            while (i < limit) {
                                if (strcmp(buffer[i], '}') == 0) {
                                    flag = 1;
                                    break;
                                }
                                i++;
                            }
                            if (flag) 
                                printf("\nNo error!");
                            else 
                                printf("\nError: Missing }\n");
                        } else  printf("\nError: Missing {\n");
                    }   else    printf("\nError: Missing )\n");
                }   else    printf("\nError: Missing ;\n");
            }   else    printf("\nError: Missing (\n");
        }   else    printf("\nError: Missing 'for'\n");
    }
}