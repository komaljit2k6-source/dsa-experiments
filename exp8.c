#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if(top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if(top == -1) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if(top == -1) {
        return '\0';
    }
    return stack[top];
}

int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/' || op == '%')
        return 2;
    else if(op == '^')
        return 3; // highest precedence
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    int i, k = 0;
    char c, top_op;

    for(i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If alphanumeric operand, add to postfix
        if(isalnum(c)) {
            postfix[k++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top != -1 && (top_op = pop()) != '(') {
                postfix[k++] = top_op;
            }
        }
        else if(isOperator(c)) {
            while(top != -1 && isOperator(peek()) && ((precedence(c) < precedence(peek())) || (precedence(c) == precedence(peek()) && c != '^'))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // pop remaining operators
    while(top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // remove trailing newline if present
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
