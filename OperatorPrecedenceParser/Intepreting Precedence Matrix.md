# Operator Precedence Parsing and Precedence Matrix Interpretation

## Precedence Matrix Table

|       | `i`  | `+`  | `*`  | `$`  | `(`  | `)`  |
|-------|------|------|------|------|------|------|
| **`i`**   |      | `>`  | `>`  | `>`  |      | `>`  |
| **`+`**   | `<`  | `>`  | `<`  | `>`  | `<`  | `>`  |
| **`*`**   | `<`  | `>`  | `>`  | `>`  | `<`  | `>`  |
| **`$`**   | `<`  | `<`  | `<`  |      | `<`  |      |
| **`(`**   | `<`  | `<`  | `<`  |      | `<`  | `=`  |
| **`)`**   |      | `>`  | `>`  | `>`  |      | `>`  |

### Explanation of Table Entries

- **`<` (Shift)**: The symbol from the **input** has **higher precedence** than the symbol on the **stack**, so you **shift** the input symbol onto the stack.
- **`>` (Reduce)**: The symbol on the **stack** has **higher precedence** than the symbol from the **input**, so you **reduce** (pop) the top of the stack.
- **`=` (Equal)**: Indicates **matching symbols**, like pairing parentheses (`(` and `)`).
- **Blank (` `)**: Represents **undefined** or **invalid** relations (e.g., `i` next to `(` is invalid).

## Step-by-Step Example: How to Use the Table

Let’s walk through an example to understand how the precedence matrix is interpreted during parsing.

### Matrix Recap:

|       | `i`  | `+`  | `*`  | `$`  | `(`  | `)`  |
|-------|------|------|------|------|------|------|
| **`i`**   |      | `>`  | `>`  | `>`  |      | `>`  |
| **`+`**   | `<`  | `>`  | `<`  | `>`  | `<`  | `>`  |
| **`*`**   | `<`  | `>`  | `>`  | `>`  | `<`  | `>`  |
| **`$`**   | `<`  | `<`  | `<`  |      | `<`  |      |
| **`(`**   | `<`  | `<`  | `<`  |      | `<`  | `=`  |
| **`)`**   |      | `>`  | `>`  | `>`  |      | `>`  |

### Steps in Parsing:

1. **Initialize**:
   - You start with the stack having the symbol `$` (indicating the end of the expression).
   - The input string is something like `i + i * i`.
   - The first symbol is `i` (an identifier).

2. **First Iteration (Stack: `$`, Input: `i`)**:
   - **Stack symbol (`y`)**: `$`
   - **Input symbol (`x`)**: `i`
   - Look up the entry in the table: `precedenceMatrix[value('$')][value('i')] = precedenceMatrix[3][0]`, which is **`<`**.
   - **Interpretation**: The input symbol `i` has **higher precedence** than `$`, so we **shift** `i` onto the stack.
   - **New Stack**: `$i`

3. **Second Iteration (Stack: `$i`, Input: `+`)**:
   - **Stack symbol (`y`)**: `i`
   - **Input symbol (`x`)**: `+`
   - Look up the entry in the table: `precedenceMatrix[value('i')][value('+')] = precedenceMatrix[0][1]`, which is **`>`**.
   - **Interpretation**: The operator `i` (operand) on the stack has **higher precedence** than `+`, so we **reduce** (pop) the top of the stack.
   - **New Stack**: `$`
   - We now need to apply a reduction rule here based on the grammar.

4. **Third Iteration (Stack: `$`, Input: `+`)**:
   - **Stack symbol (`y`)**: `$`
   - **Input symbol (`x`)**: `+`
   - Look up the entry in the table: `precedenceMatrix[value('$')][value('+')] = precedenceMatrix[3][1]`, which is **`<`**.
   - **Interpretation**: The input symbol `+` has **higher precedence** than `$`, so we **shift** `+` onto the stack.
   - **New Stack**: `$+`

5. **Fourth Iteration (Stack: `$+`, Input: `i`)**:
   - **Stack symbol (`y`)**: `+`
   - **Input symbol (`x`)**: `i`
   - Look up the entry in the table: `precedenceMatrix[value('+')][value('i')] = precedenceMatrix[1][0]`, which is **`<`**.
   - **Interpretation**: The input symbol `i` has **higher precedence** than `+`, so we **shift** `i` onto the stack.
   - **New Stack**: `$+i`

6. **Fifth Iteration (Stack: `$+i`, Input: `*`)**:
   - **Stack symbol (`y`)**: `i`
   - **Input symbol (`x`)**: `*`
   - Look up the entry in the table: `precedenceMatrix[value('i')][value('*')] = precedenceMatrix[0][2]`, which is **`>`**.
   - **Interpretation**: The operator `i` (operand) on the stack has **higher precedence** than `*`, so we **reduce** (pop) the top of the stack.
   - **New Stack**: `$+`
   - Apply the reduction rule based on the grammar.

7. **Continue this process** until you reach the end of the input string (`$`).

### Summary of Actions

- **Shift**: When the precedence relation is `<` or `=`, you shift the symbol from the input onto the stack.
- **Reduce**: When the precedence relation is `>`, you reduce by popping symbols from the stack (according to grammar rules).

## Key Points to Remember:

1. **Stack symbol (`y`)** is the top of the stack.
2. **Input symbol (`x`)** is the current symbol being processed from the input.
3. The table entry gives the relationship between the stack and input:
   - `<` means **shift** (input symbol has higher precedence).
   - `>` means **reduce** (stack symbol has higher precedence).
   - `=` typically indicates equality or matching symbols (used for handling parentheses).
4. The process continues until you either successfully parse the input (acceptance) or encounter an error.
