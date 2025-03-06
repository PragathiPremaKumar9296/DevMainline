#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare (const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int main() {
    int arr[] = {4,7,2,3,3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    bool res = false;
    qsort(arr, n, sizeof(int), compare);
    for (int i=1; i<n; i++) {
        if (arr[i] == arr[i-1]) {
            res = true;
            break;
        }
    }
    if (!res) {
        printf("Error: Does not contain duplicates");
        return 0;
    }
    printf("Suceess: Contains Duplicates");  
    return 0;
}