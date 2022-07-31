class Solution {
public:
	int lengthOfLIS(vector<int>& arr) {
		int n = arr.size();

		vector<int>dp(n, 1);
		int maxi_till_now = 1;
		int last_index = 0;

		vector<int>parent(n);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j] and 1 + dp[j] > dp[i]) {
					dp[i] = 1 + dp[j];
					parent[i] = j;
				}
				if (dp[i] > maxi_till_now) {
					maxi_till_now = dp[i];
					last_index = i;
				}
			}
		}

		vector<int>ans;
		ans.push_back(arr[last_index]);

		while (parent[last_index] != last_index) {
			last_index = parent[last_index];
			ans.push_back(arr[last_index]);
		}

		reverse(ans.begin(), ans.end());

		for (auto& i : ans) {
			cout << i << " ";
		}

		return maxi_till_now;
	}
};