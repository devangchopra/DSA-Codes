//Recursion : TLE

class Solution {
public:

	int fxn(int index, bool canBuy, vector<int>& prices) {
		if (index >= prices.size()) {
			return 0;
		}
		if (canBuy) {
			int opn1 = -prices[index] + fxn(index + 1, 0, prices);
			int opn2 = fxn(index + 1, 1, prices);

			return max(opn1, opn2);
		}
		int opn1 = prices[index] + fxn(index + 2, 1, prices);
		//one day cooldown
		int opn2 = fxn(index + 1, 0, prices);

		return max(opn1, opn2);
	}

	int maxProfit(vector<int>& prices) {
		return fxn(0, 1, prices);
	}
};

//TOP DOWN
class Solution {
public:
	int dp[5005][2];
	int fxn(int index, bool canBuy, vector<int>& prices) {
		if (index >= prices.size()) {
			return 0;
		}
		if (dp[index][canBuy] != -1) {
			return dp[index][canBuy];
		}
		if (canBuy) {
			int opn1 = -prices[index] + fxn(index + 1, 0, prices);
			int opn2 = fxn(index + 1, 1, prices);

			return dp[index][canBuy] = max(opn1, opn2);
		}
		int opn1 = prices[index] + fxn(index + 2, 1, prices);
		//one day cooldown
		int opn2 = fxn(index + 1, 0, prices);

		return dp[index][canBuy] = max(opn1, opn2);
	}

	int maxProfit(vector<int>& prices) {
		memset(dp, -1, sizeof(dp));
		return fxn(0, 1, prices);
	}
};

//BOTTOM UP
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int dp[5005][2];
		memset(dp, -1, sizeof(dp));

		//Base Case
		for (int i = 0; i <5005; i++) {
			for (int j = 0; j <= 1; j++) {
				dp[i][j] = 0;
			}
		}

		//Choice Diagram
		for (int index = n-1; index >=0; index--) {
			for (int canBuy = 0; canBuy <= 1; canBuy++) {
				int profit = INT_MAX;
				if (canBuy) {
					int opn1 = -prices[index] + dp[index + 1][0];
					int opn2 = dp[index + 1][1];
					profit = max(opn1, opn2);
				}
				else {
					int opn1 = prices[index] + dp[index + 2][1];
					//one day cooldown
					int opn2 = dp[index + 1][0];
					profit = max(opn1, opn2);
				}
				dp[index][canBuy] = profit;
			}
		}
		return dp[0][1];

	}
};