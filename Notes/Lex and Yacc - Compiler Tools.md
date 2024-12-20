# Lex and Yacc - Compiler Tools

## Overview
Lex and Yacc are widely-used tools in compiler construction. They are particularly useful for creating interpreters and compilers, where they help translate human-readable code into machine-readable instructions.

- **Lex**: A lexical analyzer generator that converts a sequence of characters (tokens) into a structured form for parsing.
- **Yacc**: "Yet Another Compiler Compiler" - a parser generator that produces a parser from a set of grammar rules and actions.

---

## Lex: Lexical Analysis Tool

### Purpose of Lex
Lex is responsible for **lexical analysis** (tokenization), breaking down the input text into meaningful units called **tokens** based on specified patterns. For instance, in a programming language, Lex might identify keywords, operators, identifiers, etc., as tokens.

### Structure of a Lex Program
A Lex program typically consists of three main sections, separated by `%%`.

#### 1. Declarations Section
- This section, found at the start of the Lex file, contains C code that you want to use in the actions or global variables needed for the program.
- C code blocks are included between `%{` and `%}`.
- Example of declarations:
    ```lex
    %{
        #include <stdio.h>
        int line_number = 1;
    %}
    ```

#### 2. Rules Section
- The rules section contains **regular expressions** (patterns) and associated **actions**.
- Each line consists of a pattern followed by the action to execute when that pattern is matched.
- Patterns are defined using regular expressions, and actions are written in C.
- Common patterns in Lex:
  - `[0-9]+` - Matches a sequence of one or more digits (integers).
  - `[a-zA-Z_][a-zA-Z0-9_]*` - Matches identifiers.
- Example rule:
    ```lex
    [0-9]+      { printf("NUMBER: %s\n", yytext); }
    ```
- In this example, the rule `[0-9]+` matches any integer and prints it as "NUMBER".

#### 3. Auxiliary Procedures Section
- This section, after the second `%%`, can contain any additional C functions required for the program.
- Auxiliary functions might handle complex actions or be utilities that the main actions rely on.
- Example of auxiliary procedures:
    ```c
    void print_token(char *token) {
        printf("TOKEN: %s\n", token);
    }
    ```

### Special Syntax and Symbols in Lex

- **`%%`**: Separates sections in the Lex file.
  - The first `%%` separates the declarations section from the rules section.
  - The second `%%` separates the rules section from the auxiliary procedures section.

- **`yytext`**: A global variable provided by Lex that holds the text matched by the current pattern.
- **`yylval`**: Used to store the value of tokens when interfacing with Yacc, especially when using tokens with associated values.

### Example Lex Program
This example matches words, numbers, and newlines.

```lex
%{
    #include <stdio.h>
    int line_number = 1;
%}

%%

[0-9]+              { printf("NUMBER: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("WORD: %s\n", yytext); }
\n                  { line_number++; }

%%

int main(void) {
    yylex();
    return 0;
}
```

---

## Yacc: Parser Generator Tool

### Purpose of Yacc
Yacc is used to parse and analyze the structure of code using a context-free grammar. It constructs a **parser** that processes tokens generated by Lex.

### Structure of a Yacc Program
A Yacc program consists of three main sections, similar to Lex.

#### 1. Declarations Section
- Contains token declarations and C code that will be used in the parser.
- Define tokens using the `%token` keyword.
- Example:
    ```yacc
    %{
        #include <stdio.h>
    %}
    %token NUMBER WORD
    ```

#### 2. Rules Section
- Contains grammar rules and actions that execute when the rule is matched.
- Rules are written in BNF (Backus-Naur Form) notation.
- Example:
    ```yacc
    statement : NUMBER { printf("Parsed NUMBER\n"); }
              | WORD   { printf("Parsed WORD\n"); }
              ;
    ```

#### 3. Auxiliary Procedures Section
- Contains helper functions needed by the parser.
- Example:
    ```c
    int yyerror(const char *s) {
        fprintf(stderr, "Error: %s\n", s);
        return 0;
    }
    ```

---

## Example of Lex and Yacc Together
To use Lex and Yacc together, you must:
1. Write a Lex file (e.g., `example.l`) for tokenization.
2. Write a Yacc file (e.g., `example.y`) for parsing.
3. Compile them together.

**Compilation Commands**:
```bash
lex example.l
yacc -d example.y
gcc lex.yy.c y.tab.c -o parser
```

---

## Summary
Lex and Yacc are essential tools in compiler design:
- **Lex** handles lexical analysis (token generation).
- **Yacc** handles syntax analysis (parsing).

These tools work together to process and understand the structure of programming languages or data formats, forming the core of compiler front-ends.

---
