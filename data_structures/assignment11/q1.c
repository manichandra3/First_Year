/*
Write a C program to implement a AVL tree with the following operation-
a) Insertion of a new node.

b) Deletion of a node.
c) Searching for a given key in the tree.
For example:
Given array, arr=[21,26,30,9,4,14,28,18,15,10,2,3,7]

Key to be searched
For example, if the search key is 15, the function should return true since 15 is present

in the AVL tree. If the search key is 90, the function should return false as 90 is not
present in the AVL tree.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} avl;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(avl *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

avl *newNode(int key)
{
    avl *node = (avl *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

avl *rightRotate(avl *y)
{
    avl *x = y->left;
    avl *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

avl *leftRotate(avl *x)
{
    avl *y = x->right;
    avl *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(avl *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

avl *insertNode(avl *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

avl *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct Node *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int searchKey(struct Node *root, int key)
{
    if (root == NULL)
        return 0;
    else if (key == root->key)
        return 1;
    else if (key < root->key)
        return searchKey(root->left, key);
    else
        return searchKey(root->right, key);
}

void printPreOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int arr[] = {21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        root = insertNode(root, arr[i]);
    }

    printf("Preorder traversal of the AVL tree: ");
    printPreOrder(root);

    int key;
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    if (searchKey(root, key))
        printf("Key %d is present in the AVL tree.\n", key);
    else
        printf("Key %d is not present in the AVL tree.\n", key);
    return 0;
}
