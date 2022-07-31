int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
	int dp[n + 1][maxWeight + 1];
	memset(dp, -1, sizeof(dp));

	//Initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= maxWeight; j++) {
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
			}
		}
	}

	//Fill the matrix
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= maxWeight; j++) {
			if (weight[i - 1] <= j) {
				dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][maxWeight];
}