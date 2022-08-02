//Check for biweekly contest

class Solution {
public:
	void fxn(vector<int>& nums, int* ans, int k) {
		cout << k << endl;
		if (k <= 0) {
			return;
		}
		//Else the function says ways to split smaller array
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}
		if (sum >= nums[k] and k != nums.size() - 1) {
			*ans++;
		}
		k=k-1;
		return fxn(nums, ans,k);
	}
	int waysToSplitArray(vector<int>& nums) {
		int ans = 0;
		fxn(nums, &ans, nums.size() - 1);
		return ans;
	}
};