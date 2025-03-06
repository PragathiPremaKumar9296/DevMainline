int roblinear(int nums[], int start, int end) {
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;  // Ensure curr is initialized

    for(int i = start; i < end; i++) {
        curr = (prev2 + nums[i] > prev1) ? prev2 + nums[i] : prev1;
        prev2 = prev1;
        prev1 = curr;
    } 
    return prev1;  // Always return prev1
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;  // No houses
    if (numsSize == 1) return nums[0];  // Only one house

    int rob1 = roblinear(nums, 0, numsSize - 1); // Exclude last house
    int rob2 = roblinear(nums, 1, numsSize);     // Exclude first house

    return (rob1 > rob2) ? rob1 : rob2;
}