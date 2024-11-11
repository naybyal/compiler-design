# Recursive Descent Parsing

Recursive descent parsing is a top-down parsing technique commonly used in compilers. It involves a set of mutually recursive functions that process the input to determine if it matches a given grammar.

## Overview
- **Definition**: Recursive descent parsing is a top-down parsing method that represents the structure of the grammar using a set of recursive functions, each handling one non-terminal in the grammar.
- **Suitability**: It works well for LL(1) grammars (grammars that can be parsed left-to-right with one token of lookahead).
- **Construction**: Each non-terminal in the grammar corresponds to a function, and the function calls mirror the structure of the grammar’s productions.

## Key Concepts

### 1. Grammar Requirements
Recursive descent parsers require that the grammar is free from:
   - **Left recursion**: This occurs when a non-terminal refers to itself on the left side of a production (e.g., `A -> Aα`). It must be eliminated for the parser to avoid infinite recursion.
   - **Ambiguity**: Ambiguous grammars (multiple parse trees for the same input) are problematic because they can lead to unpredictable behavior. 

### 2. Parse Functions
For each non-terminal symbol in the grammar, a corresponding function is created to recognize strings derived from that non-terminal:
   - **Function Calls**: Each function calls other functions representing the right-hand side of its production rules.
   - **Terminal Matching**: When a terminal symbol appears in a production, it is directly matched against the current input token.
   - **Error Handling**: If the input does not match the expected token, the parser generates an error, often handled through backtracking, or by returning an error flag.

### 3. Predictive Parsing
   - **Predictive Parsing**: A type of recursive descent parsing that does not involve backtracking. It uses **FIRST** and **FOLLOW** sets to decide which production to use based on the lookahead token, avoiding ambiguity.
   - **LL(1) Parsing**: Predictive parsers are LL(1), meaning they process the input from Left to right and construct a Leftmost derivation with 1 token lookahead.
   
### 4. FIRST and FOLLOW Sets
   - **FIRST Set**: The set of terminals that begin the strings derivable from a non-terminal.
   - **FOLLOW Set**: The set of terminals that can appear immediately to the right of a non-terminal in some "sentential" form.
   - **Usage in Parsing**: By using FIRST and FOLLOW sets, the parser determines which production to apply based on the lookahead token. This eliminates the need for backtracking.

## Example

Consider a grammar for simple arithmetic expressions:
```plaintext
E -> T E'
E' -> + T E' | ε
T -> F T'
T' -> * F T' | ε
F -> ( E ) | id
```

## Advantages

- **Simplicity**: Recursive descent parsing is straightforward to implement and mirrors the structure of the grammar.
- **Intuitive**: It directly reflects the grammar rules and is easy to follow in code form.
- **Modularity**: Each non-terminal is handled by a separate function, making it easy to manage and extend.

## Limitations

- **Limited to LL(1) Grammars**: Recursive descent parsers are suitable only for LL(1) grammars. They cannot handle left-recursive or ambiguous grammars without modification.
- **Inefficiency with Complex Grammars**: For more complex languages with significant ambiguity or backtracking requirements, recursive descent parsers become impractical.
- **Error Handling**: Detecting and recovering from syntax errors gracefully can be challenging, as the parser may stop or fail at the first unexpected token.

## Summary

Recursive descent parsing is an efficient and modular approach to top-down parsing for LL(1) grammars. Its ease of implementation makes it suitable for smaller, simpler languages and educational use. However, for more complex languages, it may require significant adaptations to manage ambiguity and left recursion.

## References

- **Compilers: Principles, Techniques, and Tools** by Alfred V. Aho, Monica S. Lam, Ravi Sethi, and Jeffrey D. Ullman.
- **Crafting Interpreters** by Robert Nystrom.
