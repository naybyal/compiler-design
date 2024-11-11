# Shift-Reduce Parsing

Shift-reduce parsing is a bottom-up parsing technique commonly used in parsers for context-free grammars. It is a type of deterministic parser that builds the parse tree from the leaves (input symbols) toward the root (start symbol) by performing two main operations: **shift** and **reduce**.

## Overview
- **Definition**: Shift-reduce parsing is a bottom-up parsing technique that works by shifting input tokens onto a stack and reducing them to non-terminals based on grammar rules.
- **Suitability**: This parsing technique is effective for grammars that can be parsed with a deterministic approach, particularly those that can be handled by **LR(0)**, **SLR(1)**, **LALR(1)**, or **CLR(1)** parsers.
- **Construction**: The parser maintains a stack to hold symbols and repeatedly shifts or reduces symbols based on the precedence rules and grammar productions.

## Key Concepts

### 1. Shift Operation
- **Shift**: The parser reads the next input token and pushes it onto the stack.
- The shift operation continues until the top of the stack contains a string that matches the right-hand side of a production rule.

### 2. Reduce Operation
- **Reduce**: When the top of the stack matches the right-hand side of a production, the parser reduces the symbols to the corresponding non-terminal.
- For example, if the stack has the string `id + id` and the production `E -> E + T` is applicable, the parser reduces the stack to `E`.

### 3. Parsing Process
The parsing process alternates between shifting and reducing until:
- The stack contains the start symbol, which means the input has been successfully parsed.
- The parser encounters an error, meaning no valid reduction is possible.

### 4. Shift-Reduce Parsing Table
The parsing process is guided by a **parsing table**, which consists of two parts:
- **Action Table**: Defines the shift and reduce actions for each state and input symbol.
- **Goto Table**: Defines the transitions between states for non-terminal symbols.

### 5. Conflicts in Shift-Reduce Parsing
- **Shift-Reduce Conflict**: This occurs when the parser is unsure whether to shift the next token onto the stack or reduce the top of the stack. This typically arises when the grammar is not unambiguous.
- **Reduce-Reduce Conflict**: This happens when there are multiple valid reductions for the same stack configuration. It typically indicates that the grammar is ambiguous.

## Example

Consider the following grammar for arithmetic expressions:

```plaintext
E -> E + T | T
T -> T * F | F
F -> ( E ) | id
```

## Example: Parsing the expression `id + id * id`

1. **Step 1**: The stack is empty, and the input is `id + id * id`.
2. **Step 2**: Shift `id` onto the stack.
3. **Step 3**: Shift `+` onto the stack.
4. **Step 4**: Shift `id` onto the stack.
5. **Step 5**: Reduce `id` to `F` based on the production `F -> id`.
6. **Step 6**: Reduce `T -> F` based on the production `T -> F`.
7. **Step 7**: Shift `*` onto the stack.
8. **Step 8**: Shift `id` onto the stack.
9. **Step 9**: Reduce `id` to `F` based on the production `F -> id`.
10. **Step 10**: Reduce `T -> F` based on the production `T -> F`.
11. **Step 11**: Reduce `T -> T * F` based on the production `T -> T * F`.
12. **Step 12**: Reduce `E -> E + T` based on the production `E -> E + T`.
13. **Step 13**: The input has been fully processed, and the stack contains the start symbol `E`, indicating successful parsing.

## Advantages

- **Efficiency**: Shift-reduce parsing is efficient because it processes input tokens in a single pass, making it faster than some other parsing techniques like recursive descent.
- **Well-Suited for LR Parsing**: It is highly effective for grammars that are suitable for LR parsing (including SLR, LALR, and CLR).
- **Error Detection**: Shift-reduce parsers can quickly detect syntax errors when no valid actions (shift or reduce) are available.

## Limitations

- **Conflicts**: Shift-reduce parsers can encounter conflicts, such as shift-reduce or reduce-reduce conflicts, especially with ambiguous or complex grammars. These conflicts must be resolved, often through lookahead or by modifying the grammar.
- **Complexity**: The construction of the parsing table, especially for Canonical LR parsers, can be complex and requires significant memory to store all possible states and transitions.
- **Limited Grammar Support**: Not all grammars can be parsed by shift-reduce parsers. They work best with deterministic context-free grammars, but ambiguities or left recursion can cause problems.

## Summary

Shift-reduce parsing is an efficient bottom-up parsing technique that builds parse trees from the leaves to the root. By alternating between shifting tokens onto the stack and reducing them to non-terminals, it parses input efficiently for grammars like LR, SLR, and LALR. However, it may encounter conflicts in ambiguous grammars, and handling these conflicts can be challenging.

## References

- **Compilers: Principles, Techniques, and Tools** by Alfred V. Aho, Monica S. Lam, Ravi Sethi, and Jeffrey D. Ullman.
- **Crafting Interpreters** by Robert Nystrom.