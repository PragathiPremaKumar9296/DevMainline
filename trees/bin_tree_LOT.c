#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode {
    struct QueueNode *next;
    struct TreeNode *node;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue *createQueue() {
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

void enqueue(struct Queue *q, struct TreeNode *node) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode *));
    newNode->next = NULL;
    newNode->node = node;

    if (q->rear == NULL)
        return NULL;
    
    q->rear->next = newNode;
    q->rear = newNode;
}

struct TreeNode *dequeue(struct Queue *q){
    if (q->front == NULL)
        return NULL;
    
    struct QueueNode *temp = q->front;
    struct TreeNode *node = temp->node;

    q->front = q->front->next;

    if (q->front == NULL)
        return NULL;
    
    free(temp);
    return node;
}

int isQueueEmpty(struct Queue *q) {
    return (q->front == NULL);
}

struct TreeNode *createNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void level_order_tree(){
    
}