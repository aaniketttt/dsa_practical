#include "postfix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Include this header for isalnum

// Function to return the precedence of operators
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {
    int i, j;
    int len = strlen(infix);
    char stack[len];
    int top = -1;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            stack[++top] = current;
        } else if (current == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            // Pop the opening parenthesis '('
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else if (isOperator(current)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = current;
        }
    }

    // Pop any remaining operators from the stack
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}
