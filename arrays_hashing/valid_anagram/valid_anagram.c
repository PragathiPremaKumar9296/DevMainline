#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_anagram( char *s, char *t) {
    int count[26] = {0};
    if (strlen(s) != strlen(t)) 
        return false;
    for (int i=0; s[i]!= '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i=0; i<26; i++) {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main() {
    char *s = "racecar";
    //char *t = "carrace";
    char *t = "ratcar";
    if (!is_anagram(s, t)) {
        printf("Error: Invalid anagram\n");
        return 1;
    }
    printf("Sucess: Valid Anagram\n");
    return 0;
}