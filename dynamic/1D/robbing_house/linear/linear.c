int rob(int* nums, int numsSize) {
    int prev1 = 0;
    int prev2 = 0;
    int curr;

    for(int i = 0; i < numsSize; i++) {
        curr = (prev2 + nums[i] > prev1) ? prev2 + nums[i] : prev1;
        prev2 = prev1;
        prev1 = curr; 
    }
    return prev1;
}