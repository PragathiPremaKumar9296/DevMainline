#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *s)
{
    int right = strlen(s) - 1;
    int left = 0;
    char temp;

    while (left < right) {
        temp = s[right];
        s[right] = s[left];
        s[left] = temp;
        left++;
        right--;
    }
}

int main()
{
    char s[] = "string";
    printf("Given String: %s\n", s);
    reverse_string(s);
    printf("Reveresed string: %s\n", s);
    return 0;
}