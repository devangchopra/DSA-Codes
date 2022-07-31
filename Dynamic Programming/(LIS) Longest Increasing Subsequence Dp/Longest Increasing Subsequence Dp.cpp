//Recursive

class Solution {
public:

	int fxn(int index , int prev_index , vector<int>& nums) {

		if (index == nums.size()) {
			return 0;
		}

		//Two Cases : Take or not take
		//1. Not take
		int len = 0 + fxn(index + 1 , prev_index , nums);

		if (prev_index == -1 or nums[index] > nums[prev_index]) {
			len = max(len, 1 + fxn(index + 1, index, nums));
			//index becomes prev_index
		}

		return len;

	}

	int lengthOfLIS(vector<int>& nums) {
		return fxn(0, -1, nums);
	}
};

//Memoozation
class Solution {
public:
	int dp[2505][2505];

	int fxn(int index , int prev_index , vector<int>& nums) {

		if (index == nums.size()) {
			return 0;
		}

		if (dp[index][prev_index + 1] != -1) {
			return dp[index][prev_index + 1];
			//Array cant have negative indexes dp[-1] ?
			//that's why a state shift
		}
		int len = 0 + fxn(index + 1 , prev_index , nums);
		if (prev_index == -1 or nums[index] > nums[prev_index]) {
			len = max(len, 1 + fxn(index + 1, index, nums));
		}

		return dp[index][prev_index + 1] = len;

	}

	int lengthOfLIS(vector<int>& nums) {
		memset(dp, -1, sizeof(dp));
		return fxn(0, -1, nums);
	}
};