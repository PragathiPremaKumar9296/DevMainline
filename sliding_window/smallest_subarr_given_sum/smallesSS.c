#include <stdio.h>
#include <limits.h>

int minSubarraySum(int arr[], int arrSize, int target)
{
    int left = 0;
    int min_length = INT_MAX;
    int sum = 0;
    int length = 0;

    for(int right = 0; right < arrSize; right++) {
        sum += arr[right];
        
        while (sum >= target) {
            length = right - left + 1;
            if (length < min_length)
                min_length = length;
            
            sum -= arr[left];
            left++;
        }
    }
    return (min_length ==  INT_MAX) ? 0 : min_length;
}

int main() {
    int arr[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = minSubarraySum(arr, n, target);
    if (result)
        printf("Smallest subarray length with sum ≥ %d is: %d\n", target, result);
    else
        printf("No valid subarray found.\n");

    return 0;
}