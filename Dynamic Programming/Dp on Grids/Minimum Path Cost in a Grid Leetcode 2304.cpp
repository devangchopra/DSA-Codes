class Solution {
public:

	int dp[51][51];

	int fxn(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int i, int j, int row, int column) {

		if (i == row - 1) {
			return grid[i][j];
		}

		int ans = INT_MAX;

		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		for (int k = 0; k < column; k++) {
			ans = min(ans, grid[i][j] + moveCost[grid[i][j]][k] + fxn(grid, moveCost, i + 1, k, row, column));
		}

		return dp[i][j] = ans;
	}


	int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
		int row = grid.size();
		int column = grid[0].size();

		memset(dp, -1, sizeof(dp));

		int ans = INT_MAX;

		for (int i = 0; i < column; i++) {
			ans = min(ans, fxn(grid, moveCost, 0, i, row, column));
		}

		return ans;
	}
};