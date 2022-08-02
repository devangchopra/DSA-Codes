class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, maxi = nums[0];
        for (auto& i : nums) {
            ans += i;
            maxi = max(ans, maxi);
            if (ans < 0) {
                ans = 0;
            }
        }
        return maxi;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        for (auto& i : nums1) {
            sum1 += i;
        }
        for (auto& i : nums2) {
            sum2 += i;
        }
        vector<int>a1;
        vector<int>a2;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            a1.push_back(nums2[i] - nums1[i]);
            a2.push_back(nums1[i] - nums2[i]);
        }
        int ans1 = maxSubArray(a1);
        int ans2 = maxSubArray(a2);
        return max(sum1 + ans1, sum2 + ans2);
    }
};