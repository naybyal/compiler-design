# Lexical Analysis

Lexical analysis is the first phase of a compiler. It involves scanning the source code to convert sequences of characters into a sequence of tokens. This process is also known as tokenization. The tokens are the atomic units of syntax, such as keywords, identifiers, literals, and operators.

## Key Concepts

### Tokens
Tokens are categorized into different types, such as:
- **Keywords**: Reserved words that have a specific meaning in the language (e.g., `if`, `else`, `while`).
- **Identifiers**: Names given to variables, functions, and other user-defined items.
- **Literals**: Constant values such as numbers and strings.
- **Operators**: Symbols that represent operations (e.g., `+`, `-`, `*`, `/`).

### Lexeme
A lexeme is a sequence of characters in the source code that matches the pattern for a token. For example, in the statement `int x = 10;`, `int`, `x`, `=`, and `10` are lexemes.

### Patterns
Patterns are rules that describe the structure of lexemes. These rules are often defined using regular expressions.

## Process of Lexical Analysis

1. **Input Buffering**: The source code is read into a buffer to facilitate efficient scanning.
2. **Scanning**: The scanner reads characters from the buffer and groups them into lexemes.
3. **Token Generation**: For each lexeme, the scanner generates a corresponding token.
4. **Error Handling**: The scanner detects and reports lexical errors, such as invalid characters or malformed tokens.

## Tools for Lexical Analysis

### Lexical Analyzers
Lexical analyzers can be implemented manually or generated using tools like Lex or Flex. These tools take a set of regular expressions and produce a scanner that can recognize the corresponding tokens.

### Example
Consider the following simple code snippet:
```c
int main() {
    int a = 5;
    printf("%d", a);
}
```
The lexical analyzer would produce the following tokens:
- `int` (keyword)
- `main` (identifier)
- `(` (symbol)
- `)` (symbol)
- `{` (symbol)
- `int` (keyword)
- `a` (identifier)
- `=` (operator)
- `5` (literal)
- `;` (symbol)
- `printf` (identifier)
- `(` (symbol)
- `"%d"` (literal)
- `,` (symbol)
- `a` (identifier)
- `)` (symbol)
- `;` (symbol)
- `}` (symbol)

## References
- "Crafting Interpreters" by Robert Nystrom
- "Compilers: Principles, Techniques, and Tools" by Alfred V. Aho, Monica S. Lam, Ravi Sethi, and Jeffrey D. Ullman

Lexical analysis is a crucial step in the compilation process, laying the foundation for subsequent phases such as syntax analysis and semantic analysis.
