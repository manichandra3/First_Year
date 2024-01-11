/*
Write a C program using a function to determine if a given AVL tree is height-balanced or not.
The function should return true if the tree is balanced, and otherwise false.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} TreeNode;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}

bool isAVL(TreeNode* node) {
    if (node == NULL)
        return true;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if (abs(leftHeight - rightHeight) <= 1 && isAVL(node->left) && isAVL(node->right))
        return true;

    return false;
}

TreeNode* createNewNode(int data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

TreeNode* insert(TreeNode* node, int data) {
    if (node == NULL) {
        return createNewNode(data);
    }

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

void showInOrder(TreeNode* node) {
    if (node == NULL)
        return;

    showInOrder(node->left);
    printf("%d ", node->data);
    showInOrder(node->right);
}

int main() {
    TreeNode* root = NULL;

    int n;
    printf("Enter the number of elements in the tree: ");
    scanf("%d", &n);

    int data;
    printf("Enter the elements of the tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Here's your tree (in-order traversal): ");
    showInOrder(root);
    printf("\n");

    if (isAVL(root))
        printf("The tree is balanced.\n");
    else
        printf("The tree is not balanced.\n");

    return 0;
}
