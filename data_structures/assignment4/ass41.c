#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 20

int stack[STACK_SIZE];
int top = -1;

void push(int data)
{
    if (top == STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        stack[++top] = data;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char equation[100];
    printf("Enter a postfix equation: ");
    scanf("%s", equation);

    int a, b, c, res;
    char *e = equation;

    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            res = *e - '0';
            push(res);
        }
        else
        {
            a = pop();
            b = pop();
            switch (*e)
            {
                case '+':
                    c = b + a;
                    break;
                case '-':
                    c = b - a;
                    break;
                case '*':
                    c = b * a;
                    break;
                case '/':
                    if (a == 0)
                    {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    c = b / a;
                    break;
            }
            push(c);
        }
        e++;
    }

    printf("\nThe result of expression %s  =  %d\n\n", equation, pop());

    return 0;
}
