class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//Brute : O(n**2)
		int ans = INT_MIN , n = prices.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, prices[i] - prices[j]);
			}
		}
		if (ans <= 0) {
			return 0;
		}
		return ans;
	}
};

//Accepted : O(n)

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int mini = prices[0];
		int profit = 0;
        int n = prices.size();
		for (int i = 1; i < n; i ++ ) {
			int cost = prices[i] - mini;
			profit = max(profit, cost);
			mini = min(mini, prices[i]);
		}

		return profit;
	}
};