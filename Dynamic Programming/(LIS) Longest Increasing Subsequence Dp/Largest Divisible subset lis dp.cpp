class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& arr) {
		//Tabulation
		int n = arr.size();
		vector<int>dp(n , 1);
		vector<int>parent(n);
        sort(arr.begin(),arr.end());
		int lastIndex = 0;
		int max_till_now = 1;

		for (int i = 0; i < n; i++) {
            parent[i]=i;
			for (int j = 0; j < i; j++) {
				if (arr[i] % arr[j] == 0 and 1 + dp[j] > dp[i]) {
					dp[i] = 1 + dp[j];
					parent[i] = j;
				}
			}
			if (dp[i] > max_till_now) {

				max_till_now = dp[i];
				lastIndex = i;
			}
		}

		vector<int>ans;
		ans.push_back(arr[lastIndex]);

		while (parent[lastIndex] != lastIndex) {
			lastIndex = parent[lastIndex];
			ans.push_back(arr[lastIndex]);
		}

		reverse(ans.begin(), ans.end());

		return ans;
	}
};