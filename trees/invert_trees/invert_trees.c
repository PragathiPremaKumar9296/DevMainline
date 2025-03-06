#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode (int val)
{
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void invertTrees(struct TreeNode *root)
{
    if (root == NULL)  // Base case to prevent recursion on NULL
        return;

    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively call the function on left and right subtrees
    invertTrees(root->left);
    invertTrees(root->right);

    printf("%d->", root->val);
}

void inorder(struct TreeNode *root)
{
    if (root == NULL)  // Base case to prevent recursion on NULL
        return;
    inorder(root->left);
    printf("%d->", root->val);
    inorder(root->right);
}

int main()
{
    struct TreeNode *root = createNode(1);
    root->left = createNode(4);
    root->right = createNode(5);

    root->left->left = createNode(2);
    root->left->right = createNode(3);
    
    root->right->left = createNode(9);
    root->right->right = createNode(10);

    inorder(root);
    printf("\n");
    invertTrees(root);

    return 0;
}

