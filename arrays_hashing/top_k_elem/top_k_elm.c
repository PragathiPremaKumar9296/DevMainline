#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1000 // Define hash table size

// Structure to store a number and its frequency
typedef struct {
    int num;   // The number itself
    int freq;  // Frequency of the number
} Element;

// Hash table entry structure
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

// Hash function
int hashFunction(int key) {
    return abs(key) % HASH_SIZE;
}

// Insert or update frequency in hash table
void insert(HashNode** hashTable, int key) {
    int index = hashFunction(key);
    HashNode* current = hashTable[index];
    while (current) {
        if (current->key == key) {
            current->value++;
            return;
        }
        current = current->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Create an array from the hash table
int createElements(HashNode** hashTable, Element* elements) {
    int count = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current) {
            elements[count].num = current->key;
            elements[count].freq = current->value;
            count++;
            current = current->next;
        }
    }
    return count;
}

// Comparison function to sort elements by frequency in descending order
int compare(const void *a, const void *b) {
    return ((Element *)b)->freq - ((Element *)a)->freq;
}

/**
 * Function to find the k most frequent elements.
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    HashNode* hashTable[HASH_SIZE] = {NULL}; // Initialize hash table
    for (int i = 0; i < numsSize; i++) {
        insert(hashTable, nums[i]);
    }
    
    Element* elements = malloc(numsSize * sizeof(Element));
    int uniqueCount = createElements(hashTable, elements);
    
    // Sort the elements array based on frequency
    qsort(elements, uniqueCount, sizeof(Element), compare);
    
    // Store top k frequent elements in result array
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = elements[i].num;
    }
    *returnSize = k; // Set the return size to k
    
    // Free hash table
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(elements);
    return result; // Return the array containing top k frequent numbers
}

// Main function to test the program
int main() {
    int nums[] = {1, 2, 2, 3, 3, 3}; // Example input array
    int k = 2; // Number of top frequent elements to find
    int returnSize; // Variable to store the size of the result array
    
    // Call the function and store the result
    int* result = topKFrequent(nums, sizeof(nums)/sizeof(nums[0]), k, &returnSize);
    
    // Print the output array
    printf("Top %d frequent elements: [", k);
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", result[i], (i == returnSize - 1) ? "" : ", ");
    }
    printf("]\n");
    
    // Free dynamically allocated memory
    free(result);
    return 0;
}
