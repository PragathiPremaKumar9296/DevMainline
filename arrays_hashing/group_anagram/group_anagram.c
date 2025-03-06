#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

// Function to compare characters for quicksort
int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Function to sort characters in a string using quicksort
void sortString(char *str) {
    qsort(str, strlen(str), sizeof(char), compare);
}

// Structure to store a word and its sorted form
typedef struct {
    char original[MAX_LENGTH];
    char sorted[MAX_LENGTH];
} Word;

int main() {
    char *strs[] = {"act", "pots", "tops", "cat", "stop", "hat"};
    int n = sizeof(strs) / sizeof(strs[0]);
    Word words[MAX_WORDS];
    int groups[MAX_WORDS] = {0}; // Array to track groups

    // Store original and sorted versions
    for (int i = 0; i < n; i++) {
        strcpy(words[i].original, strs[i]);
        strcpy(words[i].sorted, strs[i]);
        sortString(words[i].sorted);
    }

    // Group and print anagrams
    int group_id = 1;
    for (int i = 0; i < n; i++) {
        if (groups[i] == 0) { // If not yet grouped
            printf("[");
            printf("\"%s\"", words[i].original);
            groups[i] = group_id;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(words[i].sorted, words[j].sorted) == 0) {
                    printf(", \"%s\"", words[j].original);
                    groups[j] = group_id;
                }
            }
            printf("]\n");
            group_id++;
        }
    }
    return 0;
}
