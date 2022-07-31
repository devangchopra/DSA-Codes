int dp[105][1005];
int fxn(vector<int> weight, vector<int> value, int n, int maxWeight, int index) {
    if (index == n) {
        return 0;
    }
    if (maxWeight == 0) {
        return 0;
    }

    if (dp[index][maxWeight] != -1) {
        return dp[index][maxWeight];
    }

    //Two options : take or not take
    if (maxWeight >= weight[index]) {
        return dp[index][maxWeight] = max(value[index] + fxn(weight, value, n, maxWeight - weight[index], index + 1),
                                          fxn(weight, value, n, maxWeight, index + 1));
    }

    return dp[index][maxWeight] = fxn(weight, value, n, maxWeight, index + 1);


}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    // Write your code here
    memset(dp, -1, sizeof(dp));
    return fxn(weight, value, n, maxWeight, 0);
}

