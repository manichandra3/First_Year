#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char data) 
{
    if (top == MAX_SIZE - 1) 
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    stack[++top] = data;
}

char pop() 
{
    if (top == -1) 
    {
        printf("STACK UNDERFLOW\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char operator) 
{
    switch (operator) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char* infixToPrefix(char* infix) 
{
    char* prefix = (char*)malloc(sizeof(char) * MAX_SIZE);
    int len = strlen(infix);

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = infix[i];
        infix[i] = infix[j];
        infix[j] = temp;
    }

    int i, j;
    for (i = 0, j = 0; i < len; i++) 
    {
        if (infix[i] == ' ' || infix[i] == '\0') 
        {
            continue;
        }
        if (isalnum(infix[i])) 
        {
            prefix[j++] = infix[i];
        } 
        else if (infix[i] == ')') 
        {
            push(infix[i]);
        } 
        else if (infix[i] == '(') 
        {
            while (top > -1 && stack[top] != ')') 
            {
                prefix[j++] = pop();
            }
            if (top == -1) 
            {
                return "Invalid Expression";
            }
            pop();
        } 
        else if (isOperator(infix[i])) 
        {
            while (top > -1 && precedence(stack[top]) > precedence(infix[i])) 
            {
                prefix[j++] = pop();
            }
            push(infix[i]);
        } 
        else 
        {
            return "Invalid Expression";
        }
    }

    while (top > -1) {
        if (stack[top] == ')') {
            return "Invalid Expression";
        }
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    for (int i = 0, j = strlen(prefix) - 1; i < j; i++, j--) {
        char temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }

    return prefix;
}

int main() {
    char infix[MAX_SIZE];
    fgets(infix, MAX_SIZE, stdin);
    int len = strlen(infix);
    infix[len-1] = '\0';
    char* prefix = infixToPrefix(infix);

    printf("%s\n", prefix);
    return 0;
}
