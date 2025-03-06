#include <stdio.h>
#include <stdlib.h>

int compare( const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

void find_triplets(int arr[], int arr_Size, int target)
{
    int left = 0;
    int right = arr_Size - 1;
    int sum;

    qsort(arr, arr_Size, sizeof(int), compare);

    for (int i = 0; i < arr_Size; i++) {
        while (left < right) {
            sum = arr[i] + arr[left] + arr[right];
            if (sum == target) {
                printf("[%d %d %d]\n", arr[i], arr[left], arr[right]);
                return;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    printf("Triplets not found, Exiting!!!\n");
    return;
}

int main()
{
    int arr[] = {1, 4, 3, 5, 6, 2, 9, 8};
    int target = 15;
    int n = sizeof(arr) / sizeof(arr[0]);

    find_triplets(arr, n, target);

    return 0;
}