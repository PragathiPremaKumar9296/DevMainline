#include <stdio.h>

// Function to search for target in rotated sorted array
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Found target
        if (nums[mid] == target) 
            return mid;

        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            // If target is in the left half, search there
            if (nums[left] <= target && target < nums[mid]) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        // Otherwise, the right half must be sorted
        else {
            // If target is in the right half, search there
            if (nums[mid] < target && target <= nums[right]) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
    }

    return -1;  // Target not found
}

// Driver code to test the function
int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = search(nums, numsSize, target);
    printf("Index of target %d: %d\n", target, result);

    return 0;
}
