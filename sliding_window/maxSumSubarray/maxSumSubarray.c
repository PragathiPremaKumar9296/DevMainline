#include <stdio.h>
#include <stdlib.h>

int maxSumSubarray(int arr[], int arr_Size, int k) 
{
    int windowSum = 0;
    int max_len = 0;

    if (arr_Size < k)  
        return -1;

    for (int i = 0; i < k; i++) 
        windowSum += arr[i];

    max_len = windowSum;

    for (int i = k; i < arr_Size; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > max_len)
            max_len = windowSum;
    }
    return max_len;
}

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum sum of a subarray of size %d is: %d\n", k, maxSumSubarray(arr, n, k));
    return 0;
}