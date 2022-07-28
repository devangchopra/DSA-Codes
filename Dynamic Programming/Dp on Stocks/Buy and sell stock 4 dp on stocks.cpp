//RECURSIVE
class Solution {
public:

	int fxn(int index, bool canBuy, vector<int>&prices, int k) {
		//Base Case
		if (index == prices.size() or k <= 0) {
			return 0;
		}

		//Choice Diagram
		if (canBuy) {
			//Two options : liberty
			int opn1 = -prices[index] + fxn(index + 1, 0, prices, k);
			int opn2 = fxn(index + 1, 1, prices, k);

			return max(opn1, opn2);
		}

		//SelL : 1 or 0
		int opn1 = prices[index] + fxn(index + 1, 1, prices, k - 1);
		int opn2 = fxn(index + 1, 0, prices, k);
		return max(opn1, opn2);

	}

	int maxProfit(int k, vector<int>& prices) {
		return fxn(0, 1, prices, k);
	}
};

//MEMOIZATION

class Solution {
public:
	int dp[1005][2][105];

	int fxn(int index, bool canBuy, vector<int>&prices, int k) {
		//Base Case
		if (index == prices.size() or k <= 0) {
			return 0;
		}

		if (dp[index][canBuy][k] != -1) {
			return dp[index][canBuy][k];
		}

		//Choice Diagram
		if (canBuy) {
			//Two options : liberty
			int opn1 = -prices[index] + fxn(index + 1, 0, prices, k);
			int opn2 = fxn(index + 1, 1, prices, k);

			return dp[index][canBuy][k] = max(opn1, opn2);
		}

		//SelL : 1 or 0
		int opn1 = prices[index] + fxn(index + 1, 1, prices, k - 1);
		int opn2 = fxn(index + 1, 0, prices, k);
		return dp[index][canBuy][k] = max(opn1, opn2);

	}

	int maxProfit(int k, vector<int>& prices) {
		memset(dp, -1, sizeof(dp));
		return fxn(0, 1, prices, k);
	}
};



//##### CHECK ONCEEEE
//TABULATION : BOTTOM UP
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int dp[1005][2][105];
		//index -> canBuy -> k
		memset(dp, -1, sizeof(dp));

		//Base case
		for (int canBuy = 0 ; canBuy <= 1 ; canBuy++) {
			for (int lefted = 0; lefted <= k; lefted++) {
				dp[n][canBuy][lefted] = 0;
			}
		}

		for (int index = n - 1; index >= 0; index--) {
			for (int canBuy = 0; canBuy <= 1; canBuy++) {
				dp[index][canBuy][0] = 0;
			}
		}

		//Choice diagram
		for (int index = n - 1; index >= 0; index--) {
			for (int canBuy = 0; canBuy <= 1; canBuy++) {
				for (int lefted = 0; lefted <= k; lefted++) {
					int profit = INT_MIN;
					if (canBuy) {
						//Two options : liberty
						int opn1 = -prices[index] + dp[index + 1][0][k];
						int opn2 = dp[index + 1][1][k];

						profit = max(opn1, opn2);
					}
					else {
						//SelL : 1 or 0
						int opn1 = prices[index] + dp[index + 1][1][k - 1];
						int opn2 = dp[index + 1][0][k];
						profit = max(opn1, opn2);
					}
					dp[index][canBuy][lefted] = profit;
				}
			}
		}

		return dp[0][1][k];
	}
};