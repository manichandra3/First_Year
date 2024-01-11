#include<stdio.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}tree;
tree* root = NULL;

tree* insertTree(tree* root,int x)
{
    tree* newNode = (tree*)malloc(sizeof(tree));
    tree* temp = root;
    if(root==NULL)
    {
        root->data = x;
    }
    else if(x>root->data)
    {
        root->right = insert(root->right,x);
    }
    else if(x<root->data)
    {
        root->left = insert(root->left,x);
    }
    return root;
}

void printTree()
{
    if(root==NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printTree(root);
    }
    void printTreeInorder(tree* root);
    printTreeInorder(root);
}
int main ()
{
    int x;
    int n;
    for(int i = 0; i < n; i++)
    {
        insertTree(root,x);
    }

    return 0;
}