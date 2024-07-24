#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main() {
    FILE *input, *output;
    int line = 1, token_no = 0;
    char ch, str[20];
    char keyword[6][10] = {"int", "main", "if", "else", "do", "while"};

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (!input || !output) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(output, "Line no.\tToken no.\tToken\t\tLexeme\n\n");

    while ((ch = fgetc(input)) != EOF) {    
        if (strchr("+-*/", ch)) 
            fprintf(output, "%7d\t%7d\tOperator\t%7c\n", line, token_no++, ch);
        else if (strchr(";{}()?!@%", ch)) 
            fprintf(output, "%7d\t%7d\tSpecial symbol\t%7c\n", line, token_no++, ch);
        else if (isdigit(ch)) 
            fprintf(output, "%7d\t%7d\tDigit\t\t%7c\n", line, token_no++, ch);
        else if (ch == '\n')
            line++;
        else if (isalpha(ch)) {
            int i = 0;
            str[i++] = ch;
            while (isalnum(ch = fgetc(input))) 
                str[i++] = ch;
            str[i] = '\0';
            ungetc(ch, input);

            int is_keyword = 0;
            for (int j = 0; j < 6; j++) {
                if (strcmp(str, keyword[j]) == 0) {
                    is_keyword = 1;
                    break;
                }
            }
            fprintf(output, "%7d\t%7d\t%s\t%7s\n", line, token_no++, is_keyword ? "Keyword" : "Identifier", str);
        }
    }
    fclose(input);
    fclose(output);
}

