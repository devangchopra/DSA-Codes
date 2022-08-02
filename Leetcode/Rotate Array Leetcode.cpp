//Rotate Array To Right
//Brute Force

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 1) {
			return;
		}
		vector<int>temp;
		int n = nums.size(), y = n - 1;
		while (k > n) {
			k = k - n;
		}
		int x = k;
		while (x--) {
			temp.push_back(nums[y]);
			y--;
		}
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < n - k; i++) {
			temp.push_back(nums[i]);
		}
		nums = temp;
		return;
	}
};


//Better
//But gives TLE
class Solution {
public:
	void rotateByOne(vector<int> &nums) {
		int n = nums.size(), temp = nums[n - 1];
		for (int i = n - 1; i > 0; i--) {
			nums[i] = nums[i - 1];
		}
		nums[0] = temp;
	}
	void rotate(vector<int>& nums, int k) {
		for (int i = 0; i < k; i++) rotateByOne(nums);
	}
};


//Best
//O(n) and O(1)
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};