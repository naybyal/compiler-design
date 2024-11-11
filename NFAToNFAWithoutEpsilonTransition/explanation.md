# Converting NFA with ε-transition to NFA w/out ε-transition

This C program converts a Non-deterministic Finite Automaton (NFA) with epsilon (ε) transitions into an NFA without epsilon transitions. The program calculates the epsilon closure of each state and updates the transition table accordingly. 

### Key Concepts

- **Epsilon Closure**: The set of states that can be reached from a given state using only epsilon (ε) transitions, including the state itself.
- **Transition Table**: Represents the state transitions of the NFA, where for each state and input symbol, it provides the set of target states.
- **Final States**: The states that are considered accepting states. A state in the NFA without epsilon transitions is a final state if any state in its epsilon closure is a final state in the NFA with epsilon transitions.

### Detailed Steps of the Program

1. **Input NFA with Epsilon Transitions**:
   - The program starts by taking the number of states and alphabet symbols.
   - The user provides the start state and final states of the NFA.
   - Transition information is collected for each state, symbol, and target state. For epsilon transitions, a special transition for each state to every other state is input.

2. **Compute Epsilon Closure**:
   - For each state in the NFA, the epsilon closure is computed. This step finds all states reachable through epsilon transitions. A stack-based approach is used to explore the transitions.

3. **Convert to NFA without Epsilon Transitions**:
   - Using the epsilon closure information, the program constructs the transition table for the new NFA. Each state’s transitions to other states are updated to account for the epsilon closure.
   - If any state in the epsilon closure is a final state in the original NFA, the new state becomes a final state.

4. **Display the Resulting NFA**:
   - The start state, final states, and the updated transition table are displayed for the converted NFA.

### Code Breakdown

1. **Structures**:
   - `NFAWithEpsilon`: Stores information about the NFA with epsilon transitions, including states, alphabet, start state, final states, and transition table.
   - `NFAWithoutEpsilon`: Stores information about the resulting NFA without epsilon transitions.

2. **Functions**:
   - `epsilonClosure`: Computes the epsilon closure of a given state by using a stack to traverse all states reachable by epsilon transitions.
   - `convertNFA`: Converts the NFA with epsilon transitions to the NFA without epsilon transitions. It computes the new start state, final states, and updates the transition table.
   - `displayNFA`: Displays the start state, final states, and transition table for the NFA without epsilon transitions.

3. **Main Program**:
   - The program begins by collecting input for the NFA with epsilon transitions, including the number of states, alphabet symbols, transitions, and epsilon transitions.
   - The `convertNFA` function is called to generate the new NFA.
   - Finally, the `displayNFA` function prints the resulting NFA without epsilon transitions.

