/*
Write a function to trim a binary search tree, given a range [min value, max value]. The
trimmed tree should contain only the nodes whose values are within the specified range.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* deleteNode(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    free(root);
    
    // Recursively delete left and right subtrees
    deleteNode(left);
    deleteNode(right);
    
    return NULL;
}

TreeNode* trimBST(TreeNode* root, int min_val, int max_val) 
{
    if (root == NULL) 
    {
        return NULL;
    }
    
    if (root->val < min_val) 
    {
        deleteNode(root->left);
        return trimBST(root->right, min_val, max_val);
    }
    
    if (root->val > max_val) 
    {
        deleteNode(root->right);
        return trimBST(root->left, min_val, max_val);
    }
    
    root->left = trimBST(root->left, min_val, max_val);
    root->right = trimBST(root->right, min_val, max_val);
    
    return root;
}

TreeNode* createNode(int val) 
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int val) 
{
    if (root == NULL) {return createNode(val);}
    
    if (val < root->val) {root->left = insert(root->left, val);} 
    else if (val > root->val) {root->right = insert(root->right, val);}
    
    return root;
}

void inorderTraversal(TreeNode* root) 
{
    if (root == NULL) {return;}
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() 
{
    TreeNode* root = NULL;
    int n, val;
    
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);
    
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    int min, max;
    printf("Enter the trim range of the tree: ");
    scanf("%d %d", &min, &max);
    
    printf("Before trimming: ");
    inorderTraversal(root);
    printf("\n");
    
    root = trimBST(root, min, max);
    
    printf("After trimming: ");
    inorderTraversal(root);
    printf("\n");
    
    free(root);
    
    return 0;
}
