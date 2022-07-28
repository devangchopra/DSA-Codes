class Solution {
public:
    int fxn(int n, int m, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if (n < 0 or m < 0 or obstacleGrid[n][m] == 1) {
            return 0;
        }
        if (n == 0 and m == 0) {
            return 1;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        return dp[n][m] = fxn(n - 1, m, dp,obstacleGrid) + fxn(n, m - 1, dp,obstacleGrid);
    }



    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int  n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (n == m and n == 1 and obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }
        vector<vector<int>>dp(105, vector<int>(105, -1));
        return fxn(n - 1, m - 1, dp, obstacleGrid);


    }
};