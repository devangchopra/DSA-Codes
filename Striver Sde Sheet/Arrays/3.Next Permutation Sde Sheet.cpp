class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(), k, l;
		for (k = n - 2; k >= 0; k--) {
			if (nums[k] < nums[k + 1]) {
				break;
			}
			//Finding the kth breakpoint
		}
		if (k < 0) {
			//Edge Case
			//If no breakpoint
			reverse(nums.begin(), nums.end());
		}
		else {
			for (l = n - 1; l > k; l--) {
				if (nums[l] > nums[k]) {
					break;
				}
				//Finding the first greater element than k th index
			}
			swap(nums[k], nums[l]);
			//Reverse for next greater permutation
			reverse(nums.begin() + k + 1, nums.end());
		}
	}
};