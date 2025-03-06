#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 3) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate sufficient space
    int maxTriplets = numsSize * numsSize; // Estimate max triplets
    int **result = (int **)malloc(maxTriplets * sizeof(int*));
    if (!result) return NULL;

    *returnColumnSizes = (int*)malloc(maxTriplets * sizeof(int));
    if (!(*returnColumnSizes)) {
        free(result);
        return NULL;
    }

    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result[*returnSize] = (int *)malloc(3 * sizeof(int));
                if (!result[*returnSize]) return NULL; // Safety check

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

// Driver code
int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;
    
    int** triplets = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Triplets:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", triplets[i][0], triplets[i][1], triplets[i][2]);
        free(triplets[i]);
    }
    free(triplets);
    free(returnColumnSizes);

    return 0;
}
