class Solution {
public:
	vector<vector<int>>powerset;

	void fxn(vector<int>& nums, int index, vector<int> subset) {
		if (index == nums.size()) {
			powerset.push_back(subset);
			return;
		}

		//Now i have two options either to include or not

		//Option 1 : Not include
		fxn(nums, index + 1, subset);

		//Option 2 : Include
		subset.push_back(nums[index]);
		fxn(nums, index + 1, subset);
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int>subset;
		fxn(nums, 0, subset);
		return powerset;
	}
};