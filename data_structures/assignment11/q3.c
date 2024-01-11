#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} tree;

tree* getNode(int x) {
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

tree* insert(tree* node, int data) {
    if (node == NULL) {
        return getNode(data);
    }

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

void inorderTraversal(tree* node) {
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void mergeTrees(tree* node1, tree* node2) {
    if (node2 == NULL)
        return;

    mergeTrees(node1, node2->left);
    node1 = insert(node1, node2->data);
    mergeTrees(node1, node2->right);
}

int main()
{
    tree* root1 = NULL;
    tree* root2 = NULL;

    int n1;
    printf("Enter the size of the first tree: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first tree: ");
    for (int i = 0; i < n1; i++) {
        int x;
        scanf("%d", &x);
        root1 = insert(root1, x);
    }

    int n2;
    printf("Enter the size of the second tree: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second tree: ");
    for (int i = 0; i < n2; i++) {
        int x;
        scanf("%d", &x);
        root2 = insert(root2, x);
    }

    mergeTrees(root1, root2);

    printf("Merged tree in ascending order: ");
    inorderTraversal(root1);

    return 0;
}
