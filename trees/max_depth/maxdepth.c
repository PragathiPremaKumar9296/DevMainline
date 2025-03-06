#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *createNode(int val)
{
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
} 

int maxDepth(struct treeNode *root)
{
    if (root == NULL)
        return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main()
{
    struct treeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->right->right->left = createNode(6);
   
    printf("max depth: %d\n", maxDepth(root));
    return 0;
}