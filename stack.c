#include <stdio.h>
#include <ctype.h>   // for isalnum()
#define SIZE 50

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE], stack[SIZE];
    int top = -1, i = 0, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {                  // operand
            postfix[j++] = ch;
        } 
        else if (ch == '(') {               // open bracket
            stack[++top] = ch;
        } 
        else if (ch == ')') {               // close bracket
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--; // remove '('
        } 
        else {                              // operator
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = stack[top--];
            stack[++top] = ch;
        }
    }

    while (top != -1)                       // pop remaining operators
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
