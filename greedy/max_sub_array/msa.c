int maxSubArray(int* nums, int numsSize) {
    int max_sum = nums[0];
    int curr_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
         curr_sum = (nums[i] > nums[i] + curr_sum) ? nums[i] : nums[i] + curr_sum;
         max_sum = (max_sum > curr_sum) ? max_sum : curr_sum;
    }
    return max_sum;
}