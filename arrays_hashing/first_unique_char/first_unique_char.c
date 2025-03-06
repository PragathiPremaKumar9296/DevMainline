#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_COUNT 256

int firstUniqueChar(char* s)
{
    char count[ASCII_COUNT] = {0};
    int len = strlen(s);

    for(int i = 0; i < len; i++)
        count[s[i] - 'a'] += 1;
    
    for(int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

int main() 
{
    char s[] = "leetcode";
    int ret;

    ret = firstUniqueChar(s);
    if (ret < 0)
        printf("\nNo unique character\n");
    else
        printf("\nFirst unique char:%d\n", ret);
}  