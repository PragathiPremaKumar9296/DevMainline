/*
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
struct person 
{
    char name[MAX_LEN];
    int age;
};

int main()
{
    struct person p1 = {"Praga", 29};
    struct person p2 = {"Sabu", 31};

    // Access members directly
    printf("%s (age: %d), is the husband of %s (age: %d)", p2.name, p2.age, p1.name, p1.age);

    // Use pointer to point the structure
    struct person *ptr = &p1;
    printf("\nptr name: %s", ptr->name);
    printf("\nptr age: %d", ptr->age);

    // Use pointer to point the array of structure
    struct person p_arr[2] = {{"Shiva", 1}, {"Paravathi", 2}};
    struct person *p = p_arr;
    printf("\nFirst array- Name: %s,  Age: %d", p->name, p->age);
    p++;
    printf("\nSecond array- Name: %s,  Age: %d", p->name, p->age);

    // Dynamic memory allocation
    struct person *p_dyn = (struct person *) malloc(sizeof(struct person));
    if (p_dyn ==  NULL)
        return 1;
    
    // Assign values
    printf("\nEnter name: ");
    scanf("%s", p_dyn->name);
    printf("\nEnter age: ");
    scanf("%d", &p_dyn->age);

    printf("\nPerson: %s, Age: %d\n", p_dyn->name, p_dyn->age);

    // Free allocated memory
    free(p_dyn);

    return 0;
}
