//Recursion : Gives TLE
//Time Complexity ?
class Solution {
public:
	int digit_sum(int num) {
		int ans = 0;

		while (num != 0) {
			int digit = num % 10;
			ans += digit;
			num = num / 10;
		}

		return ans;
	}

	int fxn(vector<int>& nums, int index) {
		if (index == nums.size()) {
			return -1;
		}

		int sum = nums[index];
		int final_ans = -1;

		for (int i = index + 1; i < nums.size(); i++) {
			if (digit_sum(nums[index]) == digit_sum(nums[i])) {
				final_ans = max(final_ans, sum + nums[i]);
			}

		}

		return max(final_ans, fxn(nums, index + 1));
	}

	int maximumSum(vector<int>& nums) {
		return fxn(nums, 0);

	}
};

//DP on digits : Runtime Error
class Solution {
public:
	int digit_sum(int num, vector<int>&dp) {
		int ans = 0;

		if (dp[num] != -1) {
			return dp[num];
		}

		while (num != 0) {
			int digit = num % 10;
			ans += digit;
			num = num / 10;
		}

		return dp[num] = ans;
	}

	int fxn(vector<int>& nums, int index, vector<int>&dp) {
		if (index == nums.size()) {
			return -1;
		}

		int sum = nums[index];
		int final_ans = -1;

		for (int i = index + 1; i < nums.size(); i++) {
			if (digit_sum(nums[index], dp) == digit_sum(nums[i], dp)) {
				final_ans = max(final_ans, sum + nums[i]);
			}

		}

		return max(final_ans, fxn(nums, index + 1));
	}

	int maximumSum(vector<int>& nums) {
		vector<int>dp(nums.size(), -1);
		return fxn(nums, 0, dp);

	}
};


//Map : Accepted
class Solution {
public:

	int digit_sum(int num) {
		int ans = 0;

		while (num != 0) {
			int digit = num % 10;
			ans += digit;
			num = num / 10;
		}

		return ans;
	}


	int maximumSum(vector<int>& nums) {
		unordered_map<int, vector<int>>m;

		for (auto& i : nums) {
			m[digit_sum(i)].push_back(i);
		}
        

		int ans = -1;

		for (auto& e : m) {
            if(e.second.size()<=1){
                continue;
            }
            sort(e.second.begin(),e.second.end(),greater<int>());
			int sum = e.second[0]+e.second[1];
			
			ans = max(ans, sum);
		}

		return ans;
	}

};
