//
// Created by Mani Chandra Ganapathri on 30/05/23.
//
/*
Write a program implementing a function to convert a binary tree into its mirror image.
The mirror image of a binary tree is obtained by swapping the left and right children of
each node.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} tree;

tree* root_main = NULL;

tree* getNewNode(int x)
{
    tree* newNode = (tree*)malloc(sizeof(tree));
    if (newNode == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

tree* insert(tree* root, int d)
{
    if (root == NULL)
    {
        root = getNewNode(d);
        return root;
    }
    if (d < root->data)
    {
        root->left = insert(root->left, d);
    }
    else
    {
        root->right = insert(root->right, d);
    }
    return root;
}

tree* invertTree(tree* root)
{
    if (root != NULL)
    {
        invertTree(root->right);
        invertTree(root->left);
        tree* temp = root->right;
        root->right = root->left;
        root->left = temp;
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
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int x;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &x);

    for (int i = 0; i < x; i++)
    {
        int v;
        printf("Enter the value of the %d node: ", i + 1);
        scanf("%d", &v);
        root_main = insert(root_main, v);
    }

    printf("Tree before reversal(inorder): ");
    inorder(root_main);
    printf("\n");

    root_main = invertTree(root_main);

    printf("Tree after reversal(inorder): ");
    inorder(root_main);

    return 0;
}
