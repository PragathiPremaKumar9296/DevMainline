#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isAlphaNum(char s) 
{
    return (isalnum(s) != 0);
}

bool isPalindrome(char *s)
{
    int left =0, right = strlen(s) - 1;
    while (left < right) {
        
        while (left < right && !isAlphaNum(s[left]))
            left++;
        while (left < right && !isAlphaNum(s[right]))
            right--;
        
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        
        left++;
        right--;
    }
    return true;
}

int main() {
    char str1[] = "Was it a car or a cat I saw?";
    char str2[] = "tab a cat";

    printf("Output: %s\n", isPalindrome(str1) ? "true" : "false");  // Output: true
    printf("Output: %s\n", isPalindrome(str2) ? "true" : "false");  // Output: false

    return 0;
}