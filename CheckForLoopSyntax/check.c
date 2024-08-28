#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void isCorrect(char *str) {
    int semicolon = 0, bracket1 = 0, bracket2 = 0, flag = 0;

    // Trim leading and trailing spaces
    char *start = str;
    while (isspace((unsigned char)*start)) start++;

    // Check if the string starts with "for("
    if (strncmp(start, "for(", 4) != 0) {
        printf("Error: Missing 'for(' at the beginning.\n");
        return;
    }
    start += 4;

    // Find the closing parenthesis
    char *end = strchr(start, ')');
    if (end == NULL) {
        printf("Error: Missing closing parenthesis.\n");
        return;
    }

    // Extract and trim the content between parentheses
    char *content = strndup(start, end - start); // Duplicate the content between parentheses
    if (content == NULL) {
        perror("Error allocating memory");
        return;
    }

    // Validate content structure
    char *token = strtok(content, ";");
    if (token == NULL) {
        printf("Error: Missing initialization part.\n");
        free(content);
        return;
    }

    // Validate initialization
    if (strchr(token, '=') == NULL) {
        printf("Error: Missing assignment operator in initialization.\n");
        free(content);
        return;
    }

    // Validate condition
    token = strtok(NULL, ";");
    if (token == NULL) {
        printf("Error: Missing condition part.\n");
        free(content);
        return;
    }

    // Validate increment
    token = strtok(NULL, ";");
    if (token == NULL) {
        printf("Error: Missing increment part.\n");
        free(content);
        return;
    }

    // Check for any extra tokens
    if (strtok(NULL, ";") != NULL) {
        printf("Error: Extra semicolons present.\n");
        free(content);
        return;
    }

    printf("No error\n");
    free(content);
}

int main(void) {
    char filename[256];
    FILE *file;
    char *code;
    long length;

    // Get filename from user
    printf("Enter the filename containing the `for` loop statement:\n");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    // Open the file
    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Determine the file length
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file content
    code = malloc(length + 1);
    if (!code) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    // Read the entire file content
    fread(code, 1, length, file);
    code[length] = '\0'; // Null-terminate the string
    fclose(file);

    // Validate the `for` loop
    isCorrect(code);

    // Free allocated memory
    free(code);

    return 0;
}
