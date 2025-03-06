#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *createNode(int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node*));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node *reverseList(struct Node* head) {
    struct Node *curr = head, *prev = NULL, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(struct Node *head) {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Given Linked list:\n");
    printList(head);

    head = reverseList(head);

    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}