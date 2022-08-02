//Method 1

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		vector<int>odd;
		vector<int>even;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] % 2 == 0) {
				even.push_back(nums[i]);
			}
			else {
				odd.push_back(nums[i]);
			}
		}
		for (auto& i : odd) {
			even.push_back(i);
		}
		return even;
	}
};

//O(2N) and O(N)


//Two Pointer

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int i = 0, j = 0;
		while (i < nums.size() and j<nums.size()) {
			if (nums[j] % 2 == 0) {
				swap(nums[i],nums[j]);				
				i++;
				j++;
			}
			else{
				j++;
			}

		}
		return nums;
	}
};

//O(N) and O(1)