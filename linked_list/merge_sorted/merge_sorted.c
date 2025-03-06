#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head)
{
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

struct Node *mergeList(struct Node *head1, struct Node *head2)
{
    struct Node *temp = createNode(-1);
    struct Node *curr = temp;

    while (head1->next != NULL && head2->next != NULL) {
        if (head1->data <= head2->data) {
            curr = head1->next;
            head1 = head1->next;
        } else {
            curr = head2->next;
            head2 = head2->next;
        }
    }
    if (head1 != NULL) 
            curr = head1->next;
        else 
            curr = head2->next;
        
        return temp->next;
    
}