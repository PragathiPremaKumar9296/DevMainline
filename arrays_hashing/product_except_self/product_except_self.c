#include <stdio.h>
#include <stdlib.h>

int* product_except_self(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int suffix = 1;

    int *result = malloc(numsSize * sizeof(int));
    result[0] = 1;
    /* Calculate prefix multiplication */
    for (int i = 1; i < numsSize; i++) {
        result[i] = nums[i-1] * result[i-1];  
    }
     /* Calculate suffix multiplication */
    for (int i = numsSize-1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
    
    return result;
}

int main() 
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    // Call function and store result
    int* output = product_except_self(nums, numsSize, &returnSize);

    // Print result
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", output[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    // Free allocated memory
    free(output);

    return 0;
}