/*
Write a program implementing a function to determine whether a given string is palin-
drome or not using stack. A palindrome is a string that reads the same forwards and
backwards, such a ”racecar” or ”level".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode
{
    char data;
    struct StackNode* next;
} Stack;

Stack* createNode(char data)
{
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    if (newNode == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Stack* root)
{
    return (root == NULL);
}

void push(Stack** root, char data)
{
    Stack* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

char pop(Stack** root)
{
    if (isEmpty(*root))
    {
        printf("Stack is empty!\n");
        return '\0';
    }
    Stack* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int isPalindrome(const char* str)
{
    unsigned int len = strlen(str);
    int i;
    Stack* stack = NULL;

    for (i = 0; i < len / 2; i++)
    {
        push(&stack, str[i]);
    }

    if (len % 2 != 0)
    {
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] != pop(&stack))
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strlen(str)-1] = '\0';

    if (isPalindrome(str))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
