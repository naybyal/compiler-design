# Parsing : An In-Depth Review

## Introduction
Parsing is the process of analyzing a sequence of tokens to determine its grammatical structure according to a given grammar. This phase verifies the syntactic structure of the input and builds a parse tree for the subsequent compiler stages.

## Context-Free Grammars (CFG)
A Context-Free Grammar (CFG) is a formalism used to describe the syntax of programming languages. A CFG consists of a set of production rules, where each rule maps a non-terminal symbol to a sequence of terminals and/or non-terminals.

### CFG Components
- **Terminals**: Basic symbols from which strings are formed.
- **Non-Terminals**: Symbols that can be replaced by other symbols according to production rules.
- **Production Rules**: Define how terminals and non-terminals can be combined.
- **Start Symbol**: The initial non-terminal symbol for generating strings.

## Writing a Grammar
When writing grammars, we aim to eliminate ambiguity and unwanted constructs to ensure that the grammar is suitable for parsing.

### Eliminating Ambiguity
A grammar is ambiguous if there exists a string with multiple parse trees. Ambiguity can often be resolved by rewriting grammar rules, specifying precedence and associativity rules, or using parsing techniques that can handle ambiguous grammars.

### Eliminating Left Recursion
Left recursion occurs when a non-terminal refers to itself as the first symbol in one of its productions. Left recursion can be eliminated by transforming recursive productions into iterative ones.

### Left Factoring
Left factoring is a technique for refactoring a grammar to remove common prefixes, making it easier to parse in a top-down manner.

### Handling Non-Context-Free Constructs
Languages sometimes require non-context-free constructs, such as checking for matching numbers of nested elements. Such constructs are handled during semantic analysis rather than parsing.

## Top-Down Parsing
Top-Down Parsing attempts to construct the parse tree from the root down to the leaves.

### Recursive Descent Parsing
A technique that uses a set of recursive functions to process input. It’s simple to implement but only works for LL(1) grammars.

### FIRST and FOLLOW Sets
The **FIRST** set of a non-terminal is the set of terminals that begin its productions. The **FOLLOW** set of a non-terminal is the set of terminals that can appear immediately after it.
- **Shortcut to find FIRST**: If a non-terminal produces a terminal or epsilon directly, that symbol is in the FIRST set.
- **Shortcut to find FOLLOW**: For any production `A -> αBβ`, everything in FIRST(β) is in FOLLOW(B). If β is ε, FOLLOW(A) is in FOLLOW(B).

### LL(1) Grammar
An LL(1) grammar is a CFG that can be parsed by looking at only one token of input ahead. LL(1) grammars are often non-ambiguous, left-factored, and free of left recursion.

### Non-Recursive Predictive Parsing
A table-driven parsing approach that uses a stack and a parsing table, making it efficient and suitable for LL(1) grammars.

### Error Recovery in Predictive Parsing
Error recovery in predictive parsing can be implemented using panic-mode recovery, phrase-level recovery, and error productions to handle unexpected tokens.

## Bottom-Up Parsing
Bottom-Up Parsing constructs the parse tree from the leaves up to the root.

### Reductions and Handle Pruning
- **Reduction**: Replaces a substring of symbols with a non-terminal in the reverse of a production rule.
- **Handle Pruning**: Finds and reduces handles (substrings matching production bodies) to parse efficiently.

### Shift-Reduce Parsing
A common form of bottom-up parsing that uses shift and reduce operations to analyze and parse input.

### Conflicts in Shift-Reduce Parsing
Conflicts occur when there are multiple ways to apply shift and reduce operations.
- **Shift/Reduce Conflict**: A situation where the parser can either shift or reduce.
- **Reduce/Reduce Conflict**: A situation where the parser has multiple reductions to choose from.

## Simple LR Parsers (SLR)
SLR parsers are efficient bottom-up parsers that use LR(0) automata and the FOLLOW sets for parsing decisions. They are capable of parsing a limited class of grammars.

## Canonical LR Parsers (LR(1))
Canonical LR parsers, also known as LR(1) parsers, use LR(1) items that provide one token of lookahead. These parsers are more powerful than SLR parsers and can handle a larger set of grammars.

## Look-Ahead LR Parsers (LALR)
LALR parsers are a compromise between SLR and Canonical LR parsers. They have the same number of states as SLR parsers but with the lookahead capability of LR(1) parsers, making them suitable for many real-world languages.

## Comparison of SLR, CLR, and LALR Parsers

| Feature                          | Simple LR (SLR) Parser                         | Canonical LR (CLR) Parser                    | Look-Ahead LR (LALR) Parser                  |
|----------------------------------|------------------------------------------------|----------------------------------------------|----------------------------------------------|
| **Definition**                   | Uses LR(0) items and FOLLOW sets for parsing decisions. | Uses LR(1) items with one lookahead token for decisions. | Uses merged LR(1) items with minimal states similar to SLR but with lookahead like CLR. |
| **Grammar Acceptance**           | Can parse a subset of LR(1) grammars, limited in handling conflicts. | Can parse all LR(1) grammars, including most programming languages. | Can parse most grammars parsable by CLR but with reduced states. |
| **States**                       | Fewer states as it only uses LR(0) items.      | More states as each state includes a unique lookahead token for precision. | Fewer states compared to CLR due to merging, but more than SLR. |
| **Parsing Table Size**           | Smaller parsing table due to fewer states.     | Larger parsing table due to distinct LR(1) states. | Moderate-sized parsing table, as it merges similar states with same lookaheads. |
| **Conflicts**                    | Prone to conflicts in complex languages with overlapping rules. | Least prone to conflicts due to specific lookaheads. | Less prone to conflicts than SLR but may face some in very ambiguous grammars. |
| **Handling Ambiguity**           | Limited ability to handle ambiguities without external adjustments. | Superior handling of ambiguities, especially with precedence and associativity rules. | Decent ambiguity handling by merging states, though less precise than CLR. |
| **Implementation Complexity**    | Relatively simple to implement compared to CLR and LALR. | Most complex due to numerous states and specific lookahead processing. | Moderate complexity, balancing precision and state management. |
| **Use in Compilers**             | Used in simpler languages or educational parsers where full LR(1) power is not required. | Used in sophisticated compiler implementations due to high precision. | Widely used in production compilers, balancing complexity and capability. |
| **Error Detection and Recovery** | Basic error handling; less accurate due to fewer states. | Highly precise error detection, allowing for better error reporting. | Moderate error detection, better than SLR but less precise than CLR. |
| **Example**                      | Suitable for simple language subsets like expression parsing. | Suitable for fully-featured languages requiring strict syntax checks. | Common in real-world programming languages (e.g., C, Java) for efficient parsing. |



## Using Ambiguous Grammars
Ambiguous grammars can be resolved by specifying precedence and associativity to address common ambiguities, such as those caused by arithmetic operators and conditional statements.

### Precedence and Associativity to Resolve Conflicts
Operator precedence and associativity rules are used to determine the order of operations, resolving ambiguities in expressions.

### Dangling-Else Ambiguity
The dangling-else problem occurs when an `else` clause can match multiple `if` statements. It is resolved by associating `else` with the nearest `if`, either through grammar rules or semantic actions.

## Summary
Top-Down and Bottom-Up parsing techniques play critical roles in compiler design. Parsing techniques, grammar refinements, and ambiguity resolutions are foundational for building efficient, reliable parsers, as discussed in *Compilers: Principles, Techniques, and Tools* by Alfred V. Aho.

## References
1. Aho, Alfred V., Lam, Monica S., Sethi, Ravi, and Ullman, Jeffrey D. "Compilers: Principles, Techniques, and Tools," 2nd Edition, Addison-Wesley, 2006.
