int maxAscendingSum(vector<int>& nums) {
    int ans = 0;
    int sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] <= nums[i - 1]) {
            ans = max(ans, sum);
            sum = 0;
        }
        sum += nums[i];
    }
    return max(ans, sum);
}



