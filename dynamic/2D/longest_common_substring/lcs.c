#include <stdio.h>
#include <string.h>

int longestCommonSubsequence(char* text1, char* text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[len1][len2];
}

int main() {
    char text1[] = "abcde";
    char text2[] = "ace";
    printf("Longest Common Subsequence Length: %d\n", longestCommonSubsequence(text1, text2));
    return 0;
}