#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}
int evaluatePrefix(char* expr) {
    int length = strlen(expr);
    for (int i = length - 1; i >= 0; i--) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int op1 = pop();
            int op2 = pop();
            int result;

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char expr[MAX];

    printf("Enter a prefix expression (no spaces): ");
    scanf("%s", expr);

    int result = evaluatePrefix(expr);
    printf("Result = %d\n", result);

    return 0;
}
