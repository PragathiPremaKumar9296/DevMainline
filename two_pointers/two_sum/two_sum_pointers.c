#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

void findPair(int arr[], int arr_len, int target)
{
    int left = 0;
    int right = arr_len - 1;
    int sum;
    int res_arr[2];

    qsort(arr, arr_len, sizeof(int), compare);
    
    while(left < right) {
        sum = arr[left] + arr[right];
        if (sum == target) {
            res_arr[0] = left;
            res_arr[1] = right;
            printf("Pair [%d %d]", res_arr[0], res_arr[1]);
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }    
    }
    printf("No pair\n");
    return;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6, 8, 9};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPair(arr, n, target);

    return 0;
}