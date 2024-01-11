#include <stdio.h>

char stack[20];
int top = -1;

void push(char data) 
{
    if (top == 19) 
    {
        printf("Stack Overflow\n");
        return;
    } 
    else 
    {
        stack[++top] = data;
    }
}

int isempty() 
{
    if (top <= -1) 
    {
        return 1;
    }
    return 0;
}

int pop() {
    if (isempty()) 
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() 
{
    char exp[20];
    char *e;
    scanf("%s", exp);
    e = exp;
    while (*e != '\0') 
    {
        if (*e == '(' || *e == '{' || *e == '[') 
        {
            push(*e);
        } 
        else if (*e == ')' || *e == '}' || *e == ']') 
        {
            if (isempty() || (*e == ')' && pop() != '(') || (*e == '}' && pop() != '{') || (*e == ']' && pop() != '[')) 
            {
                printf("Parentheses are not balanced\n");
                return 0;
            }
        }
        e++;
    }
    if (isempty()) 
    {
        printf("Parentheses are balanced\n");
    } 
    else 
    {
        printf("Parentheses are not balanced\n");
    }
    return 0;
}
