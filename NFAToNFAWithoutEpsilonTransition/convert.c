#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100
#define MAX_ALPHABET 10

/*
 * Author: Nabiel Ahammed
 * 
 * This program converts an NFA with epsilon transitions to an NFA without epsilon transitions.
 * It computes the epsilon closure for each state and updates the transition table accordingly.
 * The NFA is represented using transition tables, start states, and final states.
 * The program reads input for the NFA with epsilon transitions and outputs the converted NFA.
 */

typedef struct {
    int nStates;
    int nAlphabet;
    int startState;
    int finalStates[MAX_STATES];
    int transitions[MAX_STATES][MAX_ALPHABET][MAX_STATES];
} NFAWithEpsilon;

typedef struct {
    int nStates;
    int nAlphabet;
    int startState;
    int finalStates[MAX_STATES];
    int transitions[MAX_STATES][MAX_ALPHABET][MAX_STATES];
} NFAWithoutEpsilon;

void epsilonClosure(NFAWithEpsilon* nfa, int state, int epsilonClosureStates[MAX_STATES]) {
    int stack[MAX_STATES];
    int top = -1;
    
    stack[++top] = state;
    epsilonClosureStates[state] = 1;

    while (top >= 0) {
        int currentState = stack[top--];
        
        for (int i = 0; i < nfa->nStates; i++) {
            if (nfa->transitions[currentState][nfa->nAlphabet][i] == 1 && !epsilonClosureStates[i]) {
                epsilonClosureStates[i] = 1;
                stack[++top] = i;
            }
        }
    }
}

void convertNFA(NFAWithEpsilon* nfa, NFAWithoutEpsilon* nfaWithoutEpsilon) {
    int epsilonClosureStates[MAX_STATES];
    
    epsilonClosure(nfa, nfa->startState, epsilonClosureStates);
    nfaWithoutEpsilon->startState = nfa->startState;

    for (int i = 0; i < nfa->nStates; i++) {
        if (epsilonClosureStates[i]) {
            nfaWithoutEpsilon->finalStates[i] = 1;
        }
    }

    for (int state = 0; state < nfa->nStates; state++) {
        for (int symbol = 0; symbol < nfa->nAlphabet; symbol++) {
            for (int targetState = 0; targetState < nfa->nStates; targetState++) {
                if (nfa->transitions[state][symbol][targetState]) {
                    int reachableStates[MAX_STATES] = {0};
                    epsilonClosure(nfa, targetState, reachableStates);
                    
                    for (int i = 0; i < nfa->nStates; i++) {
                        if (reachableStates[i]) {
                            nfaWithoutEpsilon->transitions[state][symbol][i] = 1;
                        }
                    }
                }
            }
        }
    }
}

void displayNFA(NFAWithoutEpsilon* nfa) {
    printf("Start State: %d\n", nfa->startState);
    printf("Final States: ");
    for (int i = 0; i < nfa->nStates; i++) {
        if (nfa->finalStates[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("Transition Table:\n");

    for (int i = 0; i < nfa->nStates; i++) {
        for (int j = 0; j < nfa->nAlphabet; j++) {
            printf("State %d, Symbol %d -> ", i, j);
            for (int k = 0; k < nfa->nStates; k++) {
                if (nfa->transitions[i][j][k]) {
                    printf("%d ", k);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    NFAWithEpsilon nfa;
    NFAWithoutEpsilon nfaWithoutEpsilon;

    printf("Enter the number of states: ");
    scanf("%d", &nfa.nStates);

    printf("Enter the number of alphabet symbols: ");
    scanf("%d", &nfa.nAlphabet);

    printf("Enter the start state: ");
    scanf("%d", &nfa.startState);

    printf("Enter the number of final states: ");
    int numFinalStates;
    scanf("%d", &numFinalStates);
    printf("Enter the final states: ");
    for (int i = 0; i < numFinalStates; i++) {
        int finalState;
        scanf("%d", &finalState);
        nfa.finalStates[finalState] = 1;
    }

    printf("Enter the transitions (state, symbol, target state):\n");
    for (int i = 0; i < nfa.nStates; i++) {
        for (int j = 0; j < nfa.nAlphabet; j++) {
            for (int k = 0; k < nfa.nStates; k++) {
                nfa.transitions[i][j][k] = 0;
            }
        }
    }
    
    for (int i = 0; i < nfa.nStates; i++) {
        for (int j = 0; j < nfa.nStates; j++) {
            if (i != j) {
                printf("Enter epsilon transition (state %d to state %d): ", i, j);
                int epsilon;
                scanf("%d", &epsilon);
                if (epsilon) {
                    nfa.transitions[i][nfa.nAlphabet][j] = 1;
                }
            }
        }
    }

    convertNFA(&nfa, &nfaWithoutEpsilon);

    displayNFA(&nfaWithoutEpsilon);

    return 0;
}
