int lengthOfLongestSubstring(char * s){
    int last_seen[128];
    int max_len = 0;
    int left = 0;
    memset(last_seen, -1, sizeof(last_seen));
    for (int right = 0; s[right] != '\0'; right++) {
        if (last_seen[s[right]] >= left)
            left = last_seen[s[right]] + 1;
        last_seen[s[right]] = right;
        int cur_len = right - left + 1;
        if (cur_len > max_len)
            max_len = cur_len;
    }
    return max_len;
}
