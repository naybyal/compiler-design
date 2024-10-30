/*
 * Author: Nabiel Ahammed
 * 
 * Description:
 * This program implements a simple DFA (Deterministic Finite Automaton) that processes binary strings (`0` and `1`) and determines if the string is accepted or rejected. The DFA has three states:
 *   - State 0 (q0): The starting state.
 *   - State 1 (q1): The accepting state. If the DFA ends in this state, the string is accepted.
 *   - State 2 (q2): An intermediate state.
 *
 * Transition Diagram:
 *      +-------+          0            +-------+          1          +-------+
 *      |       |---------------------->|       |--------------------->|       |
 *      |  q0   |                      |  q2   |                     |  q1   |
 *      |       |<----------------------+       |<--------------------+       |
 *      +-------+          1            +-------+          0          +-------+
 *
 * - From `q0`: 
 *     - On input `0`, it transitions to `q2`.
 *     - On input `1`, it stays in `q0`.
 *
 * - From `q1`: 
 *     - On input `0` or `1`, it stays in `q1`.
 *
 * - From `q2`: 
 *     - On input `0`, it stays in `q2`.
 *     - On input `1`, it transitions to `q1`.
 *
 * Usage:
 * The program prompts the user for a binary string and then evaluates it based on the DFA. If it ends in `q1`, the string is accepted; otherwise, it is rejected.
 */

#include <stdio.h>
#include <string.h>

int state = 0;  // Initial state is q0

void q0(char value) {
    if (value == '0') {
        state = 2;
    } else if (value == '1') {
        state = 0;
    }
}

void q2(char value) {
    if (value == '0') {
        state = 2;
    } else if (value == '1') {
        state = 1;
    }
} 

void q1(char value) {
    if (value == '0' || value == '1') {
        state = 1;
    }
}

int main() {
    char input[256];
    printf("Enter the string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        if (state == 0) {
            q0(input[i]);
        } else if (state == 1) {
            q1(input[i]);
        } else if (state == 2) {
            q2(input[i]);
        }
    }

    if (state == 1) {
        printf("\nThe string has been accepted by the DFA\n\n");
    } else {
        printf("\nThe string has been rejected by the DFA\n\n");
    }

    return 0;
}
