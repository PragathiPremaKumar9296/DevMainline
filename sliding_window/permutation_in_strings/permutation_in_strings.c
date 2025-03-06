#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkInclusion (char *s1, char *s2)
{
    int count1[26] = {0};
    int count2[26] = {0};
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i;

    if (len1 > len2)
        return false;
    
    for (i = 0; i < len1; i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    if ((memcmp(count1, count2, sizeof(count1))) == 0)
        return true;
    
    for (i = len1; i < len2; i++) {
        count2[s2[i] - 'a']++;
        count2[s2[i - len1] - 'a']--;

        if ((memcmp(count1, count2, sizeof(count1))) == 0)
            return true;
    }
    return false;
}

int main() {
    char s1[] = "ab";
    char s2[] = "eidbaooo";
    bool res;
    res = checkInclusion(s1, s2);
    if (!res) 
        printf("Failure\n");
    printf("Success\n");
    return 0;
}