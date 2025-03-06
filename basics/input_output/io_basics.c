/*
 * Write a program that asks the user for their name and age, then prints a greeting.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[100];
    int age;
    printf("Enter your name:\t");
    scanf("%s", name);
    printf("\n");
    printf("Enter your age:\t");
    scanf("%d", &age);
    printf("\n");
    printf("Hello: %s, your age: %d", name, age);
    return 0;
}
