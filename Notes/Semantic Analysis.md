# Semantic Analysis

## Introduction
Semantic analysis is the third phase in the compiler design process, following lexical and syntax analysis. While syntax analysis checks that the program follows the grammatical rules of the language, semantic analysis ensures that it is meaningful within the language's context. It verifies properties such as type correctness, scope resolution, and variable declarations, ensuring the code's logical consistency.

## Key Concepts in Semantic Analysis

### 1. Type Checking
Type checking is a primary task of semantic analysis. It ensures that the operations in the program are performed on compatible data types. There are two main types of type checking:
- **Static Type Checking**: Performed at compile time, it ensures that type-related errors are caught before execution.
- **Dynamic Type Checking**: Performed at runtime, checking the types as operations occur.

### 2. Scope and Symbol Table Management
Semantic analysis involves managing variable and function scopes to prevent naming conflicts and to resolve identifiers accurately. The **symbol table** is a data structure used to store information about identifiers (variables, functions, etc.), including their types, scopes, and declarations.

- **Scope**: Refers to the part of the program where a variable or function is accessible. Scopes can be **global**, **local**, or **nested**.
- **Symbol Table**: Stores the information for each identifier and is maintained and updated throughout the program.

### 3. Operator Overloading and Type Coercion
Some languages allow operators to work on various data types, a concept known as operator overloading. **Type coercion** is the automatic conversion of data types when needed (e.g., converting an integer to a float in mixed expressions). Semantic analysis ensures that such conversions and operator overloads are applied correctly.

## Process of Semantic Analysis

1. **Syntax Tree Traversal**: The semantic analyzer traverses the syntax tree produced by the syntax analyzer, examining each node to check for semantic correctness.
2. **Symbol Table Management**: As the code is analyzed, information about variables, functions, and other symbols is added to or removed from the symbol table.
3. **Type Checking**: The analyzer checks operations to ensure that data types are compatible.
4. **Scope Resolution**: Each identifier is checked within the current scope to avoid conflicts and ensure correct references.
5. **Error Reporting**: If a semantic violation is found, such as a type mismatch or an undeclared variable, the analyzer reports an error.

## Semantic Errors

Semantic errors are logical mistakes that violate the rules of the programming language. Common semantic errors include:
- **Type Mismatches**: Using an incorrect data type in operations (e.g., adding an integer to a string).
- **Undeclared Variables**: Referring to variables that have not been declared.
- **Out-of-Scope Variables**: Accessing a variable outside its scope.
- **Function Argument Mismatches**: Providing the wrong number or types of arguments to functions.
- **Division by Zero**: A runtime error that can be flagged during semantic analysis in some languages.

## Example of Semantic Analysis

Consider the following C-like code snippet:
```c
int a = 5;
float b = 3.0;
a = a + b;
int c = d + 2;
```

During semantic analysis, the following errors would be detected:
- **Type Mismatch**: The expression `a = a + b` involves adding an `int` to a `float`. Depending on the language, this may require explicit conversion.
- **Undeclared Variable**: `d` is used in the expression `int c = d + 2`, but `d` has not been declared.

## Semantic Analysis and Intermediate Code Generation
Semantic analysis also involves preparing the program for the next stage: intermediate code generation. By checking types, resolving scopes, and confirming valid operations, semantic analysis lays the foundation for translating code into intermediate representations that preserve type and scope correctness.

## Tools for Semantic Analysis
Semantic analysis can be implemented manually or facilitated using tools like:
- **ANTLR**: A powerful parser generator that supports custom actions for semantic checks.
- **LLVM**: Although primarily for intermediate and machine code, LLVM provides a framework where semantic analysis features can be incorporated.

## Symbol Table in Detail

### Purpose of Symbol Table
The symbol table is essential for tracking identifiers and their properties (e.g., data types, scope level, memory addresses). It plays a significant role in resolving identifiers accurately, supporting optimizations, and ensuring type safety.

### Structure of Symbol Table
Symbol tables typically consist of hash tables or binary search trees, which provide efficient insertion, lookup, and deletion operations. Each entry contains information such as the identifier’s name, type, scope level, and any associated attributes (e.g., function parameters).

### Scope Management and Symbol Table Entries
During compilation, the symbol table may use a stack-like structure for scope management. For each new scope, a new symbol table entry is pushed, allowing easy access and automatic removal of identifiers as scopes close.

## Error Handling in Semantic Analysis
Error handling in semantic analysis helps prevent program crashes and undefined behavior. Common strategies include:
- **Type Correction**: Automatic type conversion (coercion) to fix mismatches.
- **Scope Warnings**: Providing warnings for variable shadowing or unused variables.
- **Diagnostic Messages**: Providing clear and detailed messages to help programmers resolve issues.

## References
- "Compilers: Principles, Techniques, and Tools" by Alfred V. Aho, Monica S. Lam, Ravi Sethi, and Jeffrey D. Ullman
- "Engineering a Compiler" by Keith D. Cooper and Linda Torczon

Semantic analysis is crucial in ensuring that the program is not only syntactically correct but also logically consistent, thus setting the stage for the reliable execution of the code.