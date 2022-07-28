class Solution {
public:

	int fxn(int index, bool canBuy, vector<int>& prices, vector<vector<int>>& dp) {
		if (index == prices.size()) {
			return 0;
		}

		if (dp[index][canBuy] != -1) {
			return dp[index][canBuy];
		}

		//Choice diagram
		if (canBuy) {
			//Two options : either to buy or not buy
			int opn1 = -prices[index] + fxn(index + 1, 0, prices, dp);
			//Will buy : Profit = + SP - CP
			int opn2 = fxn(index + 1, 1, prices, dp);
			//Will not buy
			return dp[index][canBuy] = max(opn2, opn1);
		}

		//If cannot buy
		//Two options : Either sell or not sell
		int opn1 = prices[index] + fxn(index + 1, 1, prices, dp);
		//Sell : Profit = + SP - CP
		int opn2 = fxn(index + 1, 0, prices, dp);
		//Not sell
		return dp[index][canBuy] = max(opn1, opn2);


	}

	int maxProfit(vector<int>& prices) {
		int index = 0;
		bool canBuy = true;
		int n = prices.size();
		vector<vector<int>>dp(n, vector<int>(2, -1));
		return fxn(index, canBuy, prices, dp);
	}
};

//BOTTOM UP  COMPLETE IT:
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int dp[30001][2];
		memset(dp, -1, sizeof(dp));

		dp[n][0] = dp[n][1] = 1;
		int profit = INT_MIN;

		for (int index = 0; index <= n - 1; index++) {
			for (int canBuy = 0; canBuy <= 1; canBuy++) {
				if (canBuy) {
					//Two options : either to buy or not buy
					int opn1 = -prices[index] + dp[index + 1][0];
					//Will buy : Profit = + SP - CP
					int opn2 = dp[index + 1][1];
					//Will not buy
					profit = max(opn2, opn1);
				}

				//If cannot buy
				//Two options : Either sell or not sell
				int opn1 = prices[index] + dp[index + 1][1];
				//Sell : Profit = + SP - CP
				int opn2 = dp[index + 1][0];
				//Not sell
				profit = max(opn1, opn2);
			}
			dp[index][canBuy] = profit;
		}

		return profit;
	}
};