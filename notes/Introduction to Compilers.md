
# Introduction to Compilers

### **Author:** Nabiel Ahammed  
### **Topic:** Compiler Design and Structure

---

## **What is a Compiler?**
A **compiler** is a program that reads a program written in one language (the source language) and translates it into an equivalent program in another language (the target language).

### **Key Role of a Compiler:**
- **Error Reporting**: An important role of the compiler is to detect and report errors in the source code during translation.

### **Types of Compilers (by Functionality):**
- **Single-pass**: Scans and compiles the code in one pass.
- **Multi-pass**: Processes the source code in multiple passes.
- **Load-and-go**: Generates the code and immediately loads it for execution.
- **Debugging**: Provides additional debugging information and tools.
- **Optimizing**: Focuses on generating more efficient target code.

---

## **Compiler Phases**

The compiler operates in two main phases: **Analysis Phase** and **Synthesis Phase**.

---

### **Analysis Phase** *(of the source program)*

The **analysis phase** is responsible for breaking down the source code into its fundamental components, checking for correctness, and understanding its structure. This phase is often divided into three sub-phases:

#### **1. Lexical Analysis**
   - **Purpose**: Scans the source code to group characters into **tokens**, which are the smallest units of meaning.
   - **Tokens**: Tokens are cohesive sequences of characters (e.g., keywords, identifiers, operators).
   - **Operations**:
     - Removes blanks/spaces.
     - Ensures simplicity, efficiency, and portability.
   - **Issues**:
     - **Design simplicity**
     - **Efficiency**
     - **Portability**

#### **2. Syntax Analysis**
   - **Also known as**: Parsing or Hierarchical Analysis.
   - **Purpose**: Groups tokens into **grammatical phrases** using a **syntax tree** (often an **Abstract Syntax Tree** or AST).
   - **AST Structure**: 
     - Interior nodes represent operators.
     - Exterior nodes represent operands.
   - The syntax tree is crucial for the compiler to organize and synthesize the source code’s structure.

#### **3. Semantic Analysis**
   - **Purpose**: Checks for **semantic errors** and gathers type information for the code generation phase.
   - **Key Component**: Type checking, ensuring that each operator has permitted operands as per language specifications.

---

### **Synthesis Phase** *(of the source program)*

The **synthesis phase** takes the analyzed information to generate the final target code. It is also divided into three sub-phases:

#### **1. Intermediate Code Generation**
   - Produces an **intermediate representation** (e.g., Abstract Syntax Tree, Postfix Notation, or Three-Address Code).
   - **Properties**:
     - Simple to produce.
     - Easily translatable to the target machine.

#### **2. Code Optimization**
   - Improves the intermediate code to yield more efficient target code.
   - **Objectives**:
     - Faster execution.
     - Shorter code.
     - Lower power consumption.

#### **3. Code Generation**
   - Translates the intermediate representation into the **target language**.
   - **Crucial Aspect**: Optimal register allocation for efficient performance.

---

## **Symbol Table**
A **symbol table** is a data structure that holds records for each variable, with attributes such as type, scope, and location.

## **Tokens, Patterns, and Lexemes**
- **Token**: Sequence of characters treated as a single entity (e.g., identifiers, keywords, operators).
- **Pattern**: Set of strings in the input that produce the same token.
- **Lexeme**: Sequence of characters in the source program matched by a pattern.

---

## **Compiler Writing Tools**

1. **Parser Generators**  
   - **Input**: Context-free grammar of the programming language.
   - **Output**: Syntax analyzers.

2. **Scanner Generators**  
   - **Input**: Regular expression description of tokens.
   - **Output**: Lexical analyzers.

3. **Syntax-Directed Translation Engines**  
   - **Input**: Parse tree.
   - **Output**: Intermediate code.

4. **Automatic Code Generators**  
   - **Input**: Intermediate code.
   - **Output**: Target machine code.

5. **Data-Flow Analysis Engines**  
   - Analyzes how data moves within a program, a key part of code optimization.

---

## **Error Recovery Strategies in Lexical Analysis**
- **Panic Mode Recovery**: Deletes successive characters until a valid token is found.
- **Single Character Deletion**: Removes one character from the remaining input.
- **Character Insertion**: Inserts a missing character.
- **Character Replacement**: Replaces a character to recover.
- **Character Transposition**: Swaps two adjacent characters.

---

## **References**
- Aho, A. V., Sethi, R., & Ullman, J. D. (1986). *Compilers: Principles, Techniques, and Tools*. Addison-Wesley.
- *Modern Compiler Implementation in C* by Andrew W. Appel
- *Engineering a Compiler* by Keith D. Cooper and Linda Torczon
