#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i = 0, j = 0, limit, flag, count = 0;
    FILE *fp;
    char ch, a[1000][100];

    // Open the file for reading
    fp = fopen("test.c", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read characters from the file
    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch) || ch == '_' || ch == '=') {
            a[i][j++] = ch;
        } else {
            if (j > 0) {
                a[i][j] = '\0';
                i++;
                j = 0;
            }
            if (!isspace(ch)) {
                a[i][0] = ch;
                a[i][1] = '\0';
                i++;
            }
        }
    }

    fclose(fp);

    limit = i;
    flag = 0;

    // Check for the 'for' keyword
    for (i = 0; i < limit; i++) {
        if (strcmp(a[i], "for") == 0) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        flag = 0;
        while (i < limit && strcmp(a[i], ")") != 0) {
            if (strcmp(a[i], "(") == 0) {
                flag = 1;
                break;
            }
            i++;
        }

        if (flag) {
            flag = 0;
            while (i < limit && strcmp(a[i], ")") != 0) {
                if (strcmp(a[i], ";") == 0) count++;
                i++;
            }
            if (count == 2) {
                flag = 0;
                while (i < limit && strcmp(a[i], "{") != 0) {
                    if (strcmp(a[i], ")") == 0) {
                        flag = 1;
                        break;
                    }
                    i++;
                }
                if (flag) {
                    flag = 0;
                    while (i < limit) {
                        if (strcmp(a[i], "}") == 0) {
                            flag = 1;
                            break;
                        }
                        i++;
                    }
                    if (flag) {
                        printf("No Errors Found!\n");
                    } else {
                        printf("Error: } Is Missing!\n");
                    }
                } else {
                    printf("Error: { Is Missing!\n");
                }
            } else {
                printf("Error: ; Is Missing!\n");
            }
        } else {
            printf("Error: ) Is Missing!\n");
        }
    } else {
        printf("No For Found!\n");
    }

    return 0;
}
