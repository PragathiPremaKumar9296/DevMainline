/*
 * Store and print 5 numbers using an array.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5];
    printf("Enter the array element:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
    
    printf("Elements are: ");
    for (int i = 0; i < 5; i++)
        printf("%d \t", arr[i]);

    return 0;
}
