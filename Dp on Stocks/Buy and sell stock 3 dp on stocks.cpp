class Solution {
public:
	int dp[1000005][2][3];
	//3 because lefted -ve agar aaaya to ?

	int fxn(int index, bool canBuy, vector<int>& prices, int lefted) {

		if (index == prices.size() or lefted <= 0 ) {
			return 0;
		}
		if (dp[index][canBuy][lefted] != -1) {
			return dp[index][canBuy][lefted];
		}

		if (canBuy) {
			//Two options: buy or not buy
			int opn1 = -prices[index] + fxn(index + 1, 0, prices, lefted);
			//Buy : Money is going away from me
			int opn2 = fxn(index + 1, 1, prices, lefted);

			return dp[index][canBuy][lefted] = max(opn1, opn2);
		}

		//Sell
		int opn1 = prices[index] + fxn(index + 1 , 1, prices, lefted - 1);
		//Money coming to me
		int opn2 = fxn(index + 1 , 0, prices, lefted);
		return dp[index][canBuy][lefted] = max(opn1, opn2);

	}

	int maxProfit(vector<int>& prices) {
		//3d dp ?
		memset(dp, -1, sizeof(dp));
		return fxn(0, 1, prices, 2);

	}
};


//BOTTOM UP
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int dp[1000005][2][3];

		memset(dp, -1, sizeof(dp));

		//BASE CASES
		//index == n or lefted == 0
		for (int canBuy = 0 ; canBuy <= 1; canBuy++) {
			for (int lefted = 0; lefted <= 2; lefted++) {
				dp[n][canBuy][lefted] = 0;
			}
		}

		//Lefted===0
		for (int index = 0; index <= n; index++) {
			for (int canBuy = 0; canBuy <= 1; canBuy++) {
				dp[index][canBuy][0] = 0;
			}
		}

		//Copy paste the recurrance
		//recursion : index -> 0 to n
		//canbuy : 1 to 0
		//Lefted : 2 to 1

		for (int index = n - 1; index >= 0; index--) {
			for (int canBuy = 0; canBuy <= 1; canBuy++) {
				for (int lefted = 1; lefted <= 2; lefted++) {
					int profit = INT_MIN;
					if (canBuy) {
						//Two options: buy or not buy
						int opn1 = -prices[index] + dp[index + 1][0][lefted];
						//Buy : Money is going away from me
						int opn2 = dp[index + 1][1][lefted];

						profit = max(opn1, opn2);
					}
					else {
						//Sell
						int opn1 = prices[index] + dp[index + 1][1][lefted - 1];
						//Money coming to me
						int opn2 = dp[index + 1][0][lefted];
						profit = max(opn1, opn2);
					}


					dp[index][canBuy][lefted] = profit;
				}
			}
		}

		//Ans : dp[0][1][2]
		return dp[0][1][2];
	}
};
