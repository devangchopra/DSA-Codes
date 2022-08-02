class Solution {
public:
	vector<vector<int>>powerset;

	void fxn(vector<int>& candidates, int i, vector<int>& subset, int target) {

		if (target == 0) {
			powerset.push_back(subset);
			return;
		}
		if (i == candidates.size()) {
			//last row
			return;
		}
		if (target < 0) {
			return;
			//by no method we can make it
		}
		//now the same subset code
		//exclude
		fxn(candidates, i + 1, subset, target);

		//include
		subset.push_back(candidates[i]);
		//now i will not increment the i because it can be used again
		fxn(candidates, i, subset, target - candidates[i]);
		subset.pop_back();
		return;
	}


	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int>subset;
		fxn(candidates, 0, subset, target);
		return powerset;

	}
};