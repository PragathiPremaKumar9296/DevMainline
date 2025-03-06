#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Function to find the middle of a linked list
struct Node *findMiddle(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;  // ✅ Assign before use
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;  // ✅ Return the new head
}

// Function to merge two linked lists alternatively
void sortedMerge(struct Node *head1, struct Node *head2) {
    struct Node *temp1, *temp2;
    while (head2) {
        temp1 = head1->next;
        temp2 = head2->next;
        head1->next = head2;
        head2->next = temp1;
        head1 = temp1;
        head2 = temp2;
    }
}

// Function to reorder the list
void reorderList(struct Node *head) {
    if (!head || !head->next) return; // Edge case: Empty or single-node list
    
    // Step 1: Find the middle of the list
    struct Node *middleNode = findMiddle(head);
    struct Node *secondHalf = middleNode->next;
    middleNode->next = NULL;  // Split the list into two halves

    // Step 2: Reverse the second half
    secondHalf = reverseList(secondHalf);

    // Step 3: Merge the two halves
    sortedMerge(head, secondHalf);
}

// Test the function
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    reorderList(head);

    printf("Reordered List:\n");
    printList(head);

    return 0;
}
