/*
 * Define a struct for a student and print the details.
 */
#include <stdio.h>

#define MAX_LEN 100
struct student {
    char name[MAX_LEN];
    int age;
    float marks;
};

int main()
{
    struct student s;
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter students age: ");
    scanf("%d", &s.age);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    return 0;
}