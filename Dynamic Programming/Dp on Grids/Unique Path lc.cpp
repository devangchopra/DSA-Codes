class Solution {
public:

    int fxn(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 and n == 0) {
            return 0;
        }
        if (m == 0 or n == 0) {
            return 1;
            //because it can either go right or down
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        return dp[m][n] = fxn(m - 1, n, dp) + fxn(m, n - 1, dp);
    }

    int uniquePaths(int m, int n) {
        if (m == 1 and n == 1) {
            return 1;
        }
        vector<vector<int>>dp(105, vector<int>(105, -1));
        return fxn(m - 1, n - 1, dp);

    }
};