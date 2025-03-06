/*
 * Print the memory address of a variable using pointers.
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num = 10;
    int *ptr = &num;

    printf("value of num: %d\n", num);
    printf("address of num: %p\n", &num);
    printf("ptr: %p\n", ptr);
    printf("value of ptr:%d\n", *ptr);

    *ptr = 15;
    printf("New value: %d", num);
    return 0;
}