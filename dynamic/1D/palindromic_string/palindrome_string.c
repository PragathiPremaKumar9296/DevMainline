int expandcenter(char *s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
        count++;
    }
    return count;
}

int countSubstrings(char* s) {
    int total_count = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        total_count += expandcenter(s, i, i);
        total_count += expandcenter(s, i, i + 1);
    }

    return total_count;
}