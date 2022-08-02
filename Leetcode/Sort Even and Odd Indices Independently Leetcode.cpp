class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& nums) {
		int n = nums.size();
		vector<int>odd;
		vector<int>even;

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				even.push_back(nums[i]);
			}
			else {
				odd.push_back(nums[i]);
			}
		}

		sort(odd.begin(), odd.end(), greater<int>());
		sort(even.begin(), even.end());

		vector<int>ans;
		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				ans.push_back(even[x]);
				x++;
			}
			else {
				ans.push_back(odd[y]);
				y++;
			}
		}
		return ans;

	}
};