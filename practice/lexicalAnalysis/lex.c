#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main() {
    FILE *input, *output;
    int line = 1, tokenNumber = 0;
    char ch, next_ch = ' ';
    char str[20];
    char keyword[6][10] = {
        "void", "main", "if", "else", "printf", "while"
    };

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (!input || !output) {
        printf("Error opening file\n");
        exit(0);
    }

    fprintf(output, "Line no.\tToken no.\tToken\t\tLexeme\n");
    fprintf(output, "------------------------------------\n");

    while ((ch = fgetc(input)) != EOF) {
        if (strchr("+-*/=", ch)) {
            if (ch == (next_ch = fgetc(input))) {
                fprintf(output, "%d\t%d\tUnary Operator\t%c%c", line, ++tokenNumber, ch, ch);
            } else {
                fprintf(output, "%d\t%d\tOperator\t%c\n", line, ++tokenNumber, ch);
            }
        } else if (strchr(";{}()?!@", ch)) {
            fprintf(output, "%d\t%d\tSpecial Symbol\t%c\n", line, ++tokenNumber, ch);
        } else if (isdigit(ch)) {
            ungetc(ch, input);
            int i = 0;
            while (isdigit(ch = fgetc(input))) 
                str[i++] = ch;
            str[i] = '\0';
            ungetc(ch, input);

            fprintf(output, "%d\t%d\tDigit\t\t%s\n", line, ++tokenNumber, str);
        } else if (ch == '\n')
            line++;
        else if (isalpha(ch)) {
            int i = 0;
            do  {
                str[i++] = ch;
            } while (isalnum(ch = fgetc(input)));

            str[i] = '\0';
            ungetc(ch, input);

            int isKeyword = 0;
            for (i=0; i<6; i++) {
                if (strcmp(str, keyword[i]) == 0) {
                    isKeyword = 1;
                    break;
                }
            }
            fprintf(output, "%d\t%d\t%s\t%s\n", line, ++tokenNumber, isKeyword ? "Keyword" : "Identifier", str);
        }
    }

    fclose(input); fclose(output);
}