
class Solution {
public:

	int dp[50001][2];

	int fxn(int index, bool canBuy, vector<int>& prices, int fee) {
		if (index == prices.size()) {
			return 0;
		}

		if (dp[index][canBuy] != -1) {
			return dp[index][canBuy];
		}

		if (canBuy) {
			int opn1 = -prices[index] + fxn(index + 1, 0, prices, fee);
			int opn2 = fxn(index + 1, 1, prices, fee);

			return dp[index][canBuy] = max(opn1, opn2);
		}
		int opn1 = prices[index] + fxn(index + 1, 1, prices, fee) - fee;
		int opn2 = fxn(index + 1, 0, prices, fee);

		return dp[index][canBuy] = max(opn2, opn1);
	}

	int maxProfit(vector<int>& prices, int fee) {
		memset(dp, -1, sizeof(dp));
		return fxn(0, 1, prices, fee);
	}
};
