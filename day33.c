/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

int main() {
    char exp[100];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    char stack[100];
    int top = -1;

    char result[100];
    int k = 0;

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (isalnum(ch)) {
            result[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                result[k++] = stack[top--];
            }
            if (top >= 0) top--;
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(ch)) {
                result[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top >= 0) {
        result[k++] = stack[top--];
    }

    result[k] = '\0';

    printf("Postfix expression: %s", result);

    return 0;
}