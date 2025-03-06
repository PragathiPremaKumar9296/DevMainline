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

void inorderTrees (struct TreeNode *root)
{
    if (root == NULL) 
        return;
    
    inorderTrees(root->left);
    printf("%d->", root->val);
    inorderTrees(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct TreeNode *root) {
    if (root == NULL) return;
    printf("%d->", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct TreeNode *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d->", root->val);
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

    inorderTrees(root);
    printf("\n");
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    return 0;
}

