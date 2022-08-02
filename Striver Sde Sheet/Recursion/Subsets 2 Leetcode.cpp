//Better


class Solution {
public:
	vector<vector<int>> v;

	void fxn(vector<int>& nums, int i, vector<int> subset) {
		if (i == nums.size()) {
			v.push_back(subset);
			return;
		}

		int itr = i;
		// exclude
		//skip all equivalent
		while (i + 1 < nums.size() and nums[i] == nums[i + 1]) {
			i++;
		}

		//Then the code is same
		fxn(nums, i + 1, subset);


		// include
		subset.push_back(nums[itr]);
		fxn(nums, itr + 1, subset);


	}


	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> temp;
		fxn(nums, 0, temp);
		return v;
	}
};

class Solution {
public:

	void fxn(vector<int>& nums, int index, vector<int> subset, set<vector<int>>& powerset) {
		if (index == nums.size()) {
			sort(subset.begin(), subset.end());
			powerset.insert(subset);
			return;
		}
		fxn(nums, index + 1, subset, powerset);
		subset.push_back(nums[index]);
		fxn(nums, index + 1, subset, powerset);
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set<vector<int>>powerset;
		vector<int>subset;
		vector<vector<int>>ans;
		fxn(nums, 0, subset, powerset);
		for (auto& i : powerset) {
			ans.push_back(i);
		}
		return ans;
	}
};



