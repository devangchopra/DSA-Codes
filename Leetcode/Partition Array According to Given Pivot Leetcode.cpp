
class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector<int>small, large;
		int count = 0;
		for (auto& i : nums) {
			if (i < pivot) {
				small.push_back(i);
			}
			else if (i > pivot) {
				large.push_back(i);
			}
			else if (i == pivot) {
				count++;
			}
		}
		vector<int>ans;
		for (auto& i : small) {
			ans.push_back(i);
		}
		while(count--){
			ans.push_back(pivot);
		}
		for(auto& i:large){
			ans.push_back(i);
		}
		return ans;

	}
};


