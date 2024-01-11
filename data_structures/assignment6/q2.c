#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} tree;

tree* root = NULL;

tree* create(int value)
{
    tree* new_node = (tree*)malloc(sizeof(tree));
    if (new_node == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree *insert(tree *root, int value) 
{
    if (root == NULL)
    {
        root = create(value);
        return root;
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

int findMin(tree* root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1; 
    }

    tree* current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }

    return current->data;
}

int findMax(tree* root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1; 
    }

    tree* current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }

    return current->data;
}
// question 2 part B
void preorder(tree* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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

void postorder(tree* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter node value: ");
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("\nMinimum element: %d\n", findMin(root));
    printf("Maximum element: %d\n", findMax(root));

    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
