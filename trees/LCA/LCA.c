#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *leastCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (root == NULL)
        return NULL;
    
    if (p->val < root->val && q->val < root->val)
        return leastCommonAncestor(root->left, p, q);
    
    if (p->val > root->val && q->val > root->val)
        return leastCommonAncestor(root->right, p, q);
    
    return root;
}

int main () {
    struct TreeNode* root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(8);
    root->left->left = createNode(0);
    root->left->right = createNode(4);
    root->left->right->left = createNode(3);
    root->left->right->right = createNode(5);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    struct TreeNode* p = root->left; // Node 2
    struct TreeNode* q = root->right; // Node 8

    struct TreeNode* lca = leastCommonAncestor(root, p, q);
    printf("The LCA of nodes %d and %d is: %d\n", p->val, q->val, lca->val);

    return 0;
}