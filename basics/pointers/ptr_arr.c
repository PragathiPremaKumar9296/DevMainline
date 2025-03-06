/*
 * Print an array using a pointer.
 */
#include <stdio.h>

int main()
{
    int arr[] = {2,1,4,3,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *ptr = arr;

    for (int i = 0; i<size; i++)
        printf("%d\n", *(ptr + i));
    return 0;
}