# Compiler Design

This repository contains implementations of various components of a compiler, primarily written in C. It includes several key modules related to compiler construction, such as lexical analysis, parsing, and intermediate code generation.

## Features

- **Lexical Analysis**: Implements a lexer to tokenize input source code.
- **Parsing Techniques**:
  - Operator Precedence Parser
  - Recursive Descent Parser
  - DFA (Deterministic Finite Automaton)
- **Intermediate Code Generation**: Generates intermediate code in the form of quadruples.
- **Syntax Checking**: Includes functions to check the syntax of constructs like loops.

## Directory Structure

- `CheckForLoopSyntax/`: Syntax analyzer for-loop constructs.
- `DFA/`: Implementation of a Deterministic Finite Automaton.
- `IntermediateCodeAsQuadruple/`: Module for generating quadruple representations.
- `LexicalAnalysisUsingC/`: Lexer implementation.
- `OperatorPrecedenceParser/`: Parser based on operator precedence.
- `RecursiveDescentParser/`: Implements a recursive descent parser.

## Getting Started

To run the project, clone this repository and navigate to the desired module:

```bash
git clone https://github.com/naybyal/compiler-design.git
cd compiler-design
