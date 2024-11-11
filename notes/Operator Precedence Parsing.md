# Operator Precedence Parsing

Operator precedence parsing is a technique used for parsing expressions in programming languages where operators have defined precedence and associativity. It is commonly used for handling expressions involving operators like `+`, `-`, `*`, `/`, etc.

## Overview
- **Definition**: Operator precedence parsing is a top-down, non-recursive parsing technique used to parse expressions with operators based on their precedence. It operates by using a precedence matrix to guide the parsing process.
- **Suitability**: This method works well when the grammar involves operators with clear precedence and associativity rules.
- **Construction**: The parser uses a stack to manage the operators and operands, and compares the precedence of operators to decide whether to shift or reduce the stack content.

## Key Concepts

### 1. Precedence Relations
Operator precedence defines the priority of operators during parsing. The precedence relations help the parser determine the correct order of operations.

- **Precedence Matrix**: The precedence matrix is a 2D table that defines the relationships between pairs of operators. For each pair of operators `A` and `B`, the matrix indicates whether `A` has higher, lower, or equal precedence compared to `B`.
  
### 2. Writing the Precedence Matrix
The precedence matrix is typically constructed using the following rules:

- `> (greater than)`: Indicates that the operator on the left has higher precedence.
- `< (less than)`: Indicates that the operator on the right has higher precedence.
- `= (equal to)`: Indicates that the operators have the same precedence.

**Example Precedence Matrix**:

Consider the following set of operators with their precedence:
- `*` (multiplication) and `/` (division) have higher precedence than `+` (addition) and `-` (subtraction).
- `+` and `-` have the same precedence.

| Operator | `+` | `-` | `*` | `/` |
|----------|-----|-----|-----|-----|
| `+`      | `=` | `=` | `<` | `<` |
| `-`      | `=` | `=` | `<` | `<` |
| `*`      | `>` | `>` | `=` | `=` |
| `/`      | `>` | `>` | `=` | `=` |

This matrix indicates that:
- `+` and `-` have equal precedence with each other.
- `*` and `/` have higher precedence than `+` and `-`, and equal precedence with each other.

### 3. Operator Precedence Parsing Algorithm
The operator precedence parser uses a stack and a precedence matrix to determine whether to **shift** (push the next token onto the stack) or **reduce** (apply a production rule to the stack).

- **Shift Operation**: When the next token has a higher precedence than the top of the stack, the token is shifted onto the stack.
- **Reduce Operation**: When the next token has lower precedence than the top of the stack, a reduction is performed based on the grammar.

The parser uses the precedence matrix to compare operators and decide whether to perform a shift or reduce operation.

### 4. Example Grammar and Parsing

Consider the following simple grammar for arithmetic expressions:

```plaintext
E -> E + T | E - T | T
T -> T * F | T / F | F
F -> ( E ) | id
```

## 5. Parsing Example

Let’s parse the expression `id + id * id`.

- **Step 1**: Initialize an empty stack.
- **Step 2**: Start scanning from the leftmost token, `id`, which is a terminal.
    - Shift `id` onto the stack.
- **Step 3**: The next token is `+`, which is an operator.
    - Check the precedence matrix for `id` and `+`. Since `id` has no precedence over `+`, perform a shift.
- **Step 4**: The next token is `id`, which is a terminal.
    - Shift `id` onto the stack.
- **Step 5**: The next token is `*`, an operator.
    - Compare `+` and `*` in the precedence matrix. Since `*` has higher precedence than `+`, shift `*` onto the stack.
- **Step 6**: The next token is `id`.
    - Shift `id` onto the stack.
- **Step 7**: End of input.
    - The parser uses the precedence matrix to apply reductions. The `id * id` is reduced to `T`, and then `E + T` is reduced to `E`.

## 6. Error Handling

Operator precedence parsers can detect syntax errors when the precedence matrix cannot decide on an operation (i.e., when there’s no valid shift or reduce operation). In such cases, the parser can report an error.

## Advantages

- **Efficiency**: Operator precedence parsing is non-recursive and runs in linear time.
- **Simple to Implement**: It’s relatively easy to implement for grammars that fit the operator precedence model.
- **Clear Handling of Operator Precedence**: This method provides a clear mechanism to handle operator precedence and associativity.

## Limitations

- **Limited to Context-Free Grammars**: Operator precedence parsers are limited to context-free grammars and cannot handle certain complex constructs.
- **Not Suitable for All Grammars**: It can only handle expressions with clear operator precedence; more complex grammars, such as those involving non-associative operators, are not suitable.
- **Requires Precedence Matrix**: The construction of a precedence matrix for certain languages may be non-trivial.

## Summary

Operator precedence parsing is an efficient technique for parsing arithmetic expressions with operators. It uses a precedence matrix to guide the parsing process, ensuring that operators are applied in the correct order based on their precedence and associativity. It is suitable for simple grammars involving arithmetic operations but has limitations for more complex languages.

## References

- **Compilers: Principles, Techniques, and Tools** by Alfred V. Aho, Monica S. Lam, Ravi Sethi, and Jeffrey D. Ullman.
- **Crafting Interpreters** by Robert Nystrom.
