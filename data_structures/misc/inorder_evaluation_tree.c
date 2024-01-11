#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit function

typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} tree;

tree* createNode(char data) {
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

tree* buildExpressionTree(char postfix[]) {
    tree* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            tree* newNode = createNode(postfix[i]);
            stack[++top] = newNode;
        } else if (isOperator(postfix[i])) {
            tree* newNode = createNode(postfix[i]);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top];
}

int evaluate(tree* root) {
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return root->data - '0';

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

int main() {
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%[^\n]", postfix);

    tree* root = buildExpressionTree(postfix);
    int result = evaluate(root);

    printf("Result: %d\n", result);

    // Free allocated memory
    free(root);

    return 0;
}
