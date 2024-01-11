#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
}tree;

tree* root = NULL;

int max(int a, int b);

tree* getNewNode(int data)
{
    tree* newNode = (tree*)malloc(sizeof(tree));
    if (newNode == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

tree *insert(tree *root, int value) {
    if (root == NULL)
    {
        root = getNewNode(value);
        return root;
    }

    if (value < root->info)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->info)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(tree* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

int height(tree* root)
{
    if (root == NULL)
    {
        return -1;
    }

    return 1 + max(height(root->left), height(root->right));
}

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main() {
    int n;
    printf("ENTER THE NUMBER OF NODES:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        root = insert(root, d);
    }
    printf("Tree contents:");
    inorder(root);
    printf("\n");
    printf("%d", height(root));
}