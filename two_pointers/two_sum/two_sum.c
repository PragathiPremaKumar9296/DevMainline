#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

// Compare function for sorting pairs by value
int compare (const void *a, const void *b) {
    return ((Pair *)a)->value - ((Pair *)b)->value;
}

// Two Sum function using two-pointer approach
int *two_sum(int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 2; // Always return 2 indices
    int *res = (int *)malloc(2 * sizeof(int));
    if (!res) return NULL; // Check for allocation failure

    Pair *arr = (Pair *)malloc(numsSize * sizeof(Pair));
    if (!arr) {
        free(res);
        return NULL; // Check for allocation failure
    }

    // Store original indices before sorting
    for (int i = 0; i < numsSize; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    // Sort array based on values
    qsort(arr, numsSize, sizeof(Pair), compare);

    // Two-pointer approach
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = arr[left].value + arr[right].value;
        if (sum == target) {
            res[0] = arr[left].index;
            res[1] = arr[right].index;
            free(arr);
            return res;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // No valid pair found
    free(arr);
    free(res);
    *returnSize = 0;
    return NULL;
}

// Driver code
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    
    int* result = two_sum(nums, 4, target, &returnSize);

    if (returnSize == 2) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result); // Free allocated memory
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
