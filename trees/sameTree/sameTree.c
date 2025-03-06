#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

bool isSameTree(struct treeNode *p, struct treeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    
    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct treeNode *createNode (int val)
{
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    bool res;

    struct treeNode *p = createNode(1);
    p->left = createNode(2);
    p->right = createNode(3);

    struct treeNode *q = createNode(1);
    q->left = createNode(2);
    q->right = createNode(3);

    if (isSameTree(p, q))
        printf("The trees are the same.\n");
    else
        printf("The trees are NOT the same.\n");

    return 0;
}