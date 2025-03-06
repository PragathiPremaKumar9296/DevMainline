int expandcenter(char *s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int max_len = 0;
    int start = 0;

    int n = strlen(s);

    if (n == 0)
        return " ";

    for (int i = 0; i < n; i++) {
        int len1 = expandcenter(s, i, i);
        int len2 = expandcenter(s, i, i + 1);
        int len = (len1 > len2) ? len1 : len2;

        if (len > max_len) {
            max_len = len;
            start = i - (len - 1)/2 ;
        }
    }
    char *result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0'; 
    return result;
}