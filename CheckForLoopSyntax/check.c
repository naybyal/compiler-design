#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void isCorrect(const char *str) {
    // Trim leading spaces
    while (isspace((unsigned char)*str)) str++;

    // Check if the string starts with "for("
    if (strncmp(str, "for(", 4) != 0) {
        printf("Error: Missing 'for(' at the beginning.\n");
        return;
    }
    str += 4; // Move past "for("

    // Find the closing parenthesis
    const char *end = strchr(str, ')');
    if (!end) {
        printf("Error: Missing closing parenthesis.\n");
        return;
    }

    // Check semicolons
    int semicolons = 0;
    char *content = strndup(str, end - str);
    if (!content) {
        perror("Error allocating memory");
        return;
    }

    char *token = strtok(content, ";");
    while (token) {
        semicolons++;
        token = strtok(NULL, ";");
    }

    if (semicolons != 3) {
        printf("Error: Incorrect number of semicolons.\n");
        free(content);
        return;
    }

    // Validate parts
    char *init = strtok(strdup(content), ";");
    if (!strchr(init, '=')) {
        printf("Error: Missing assignment operator in initialization.\n");
        free(content);
        return;
    }

    char *condition = strtok(NULL, ";");
    if (!condition || strlen(condition) == 0) {
        printf("Error: Missing condition part.\n");
        free(content);
        return;
    }

    char *increment = strtok(NULL, ";");
    if (!increment || strlen(increment) == 0) {
        printf("Error: Missing increment part.\n");
        free(content);
        return;
    }

    printf("No error\n");
    free(content);
}

int main(void) {
    char filename[256];
    printf("Enter the filename containing the `for` loop statement:\n");
    if (!fgets(filename, sizeof(filename), stdin)) {
        perror("Error reading filename");
        return 1;
    }
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *code = malloc(length + 1);
    if (!code) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    fread(code, 1, length, file);
    code[length] = '\0';
    fclose(file);

    isCorrect(code);
    free(code);

    return 0;
}
