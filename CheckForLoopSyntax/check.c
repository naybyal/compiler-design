#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    FILE *fp;
    char ch;
    char buffer[MAX_SIZE];
    int i = 0;
    int has_for = 0, has_open_paren = 0, has_close_paren = 0;
    int has_open_brace = 0, has_close_brace = 0;
    int semicolon_count = 0;

    // Open the file
    fp = fopen("test.c", "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    // Read file content into buffer
    while ((ch = fgetc(fp)) != EOF && i < MAX_SIZE - 1) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0'; // Null-terminate the string
    fclose(fp);

    // Parse the buffer
    for (i = 0; buffer[i] != '\0'; i++) {
        if (strncmp(&buffer[i], "for", 3) == 0 && !isalnum(buffer[i + 3]) && buffer[i + 3] == ' ') {
            has_for = 1;
        }
        if (buffer[i] == '(') has_open_paren = 1;
        if (buffer[i] == ')') has_close_paren = 1;
        if (buffer[i] == '{') has_open_brace = 1;
        if (buffer[i] == '}') has_close_brace = 1;
        if (buffer[i] == ';') semicolon_count++;
    }

    // Syntax checking based on flags and counts
    if (!has_for) {
        printf("No 'for' Found!\n");
    } else if (!has_open_paren) {
        printf("Error: '(' Is Missing!\n");
    } else if (!has_close_paren) {
        printf("Error: ')' Is Missing!\n");
    } else if (semicolon_count != 2) {
        printf("Error: Incorrect number of ';'!\n");
    } else if (!has_open_brace) {
        printf("Error: '{' Is Missing!\n");
    } else if (!has_close_brace) {
        printf("Error: '}' Is Missing!\n");
    } else {
        printf("No Errors Found!\n");
    }

    return 0;
}
