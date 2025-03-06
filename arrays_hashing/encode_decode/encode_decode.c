#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Encodes a list of strings to a single string */
char* encode(char** strs, int strsSize) {
    if (strsSize == 0) return strdup("");
    int total = 0;
    for (int i = 0; i < strsSize; i++)
        total += snprintf(NULL, 0, "%d#", (int)strlen(strs[i])) + strlen(strs[i]);

    char* result = (char*)malloc(total + 1);
    result[0] = '\0'; // Start with an empty string
    for (int i = 0; i < strsSize; i++) {
        char temp[10];
        snprintf(temp, sizeof(temp), "%d#", (int)(strlen(strs[i])));
        strcat(result, temp);
        strcat(result, strs[i]);
    }
    return result;
}

/**
 * Decodes a single string to a list of strings.
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** decode(char* s, int* returnSize) {
    if (strlen(s) == 0) {
        *returnSize = 0;
        return NULL;
    } 
    int capacity = 10;
    char **result = (char **)malloc(capacity * sizeof(char *));
    int count = 0;
    char *ptr = s;
    while(*ptr) {
        int len = atoi(ptr);
        while(*ptr != '#') ptr++;
        ptr++;
        
        result[count] = (char *)malloc(len + 1);
        strncpy(result[count], ptr, len);
        result[count][len] = '\0';

        ptr += len;
        count++;

        if (count >= capacity) {
                    capacity *= 2;
                    result = (char**)realloc(result, capacity * sizeof(char*));
        }
    }
    *returnSize = count;
    return result;
}
int main() {
    char* strs[] = {"neet", "code", "love", "you"};
    int strsSize = 4;

    // Encode
    char* encoded = encode(strs, strsSize);
    printf("Encoded: %s\n", encoded);

    // Decode
    int decodedSize;
    char** decoded = decode(encoded, &decodedSize);

    printf("Decoded:\n");
    for (int i = 0; i < decodedSize; i++) {
        printf("\"%s\"\n", decoded[i]);
        free(decoded[i]);
    }

    // Free memory
    free(decoded);
    free(encoded);

    return 0;
}
