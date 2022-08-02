
//TLE
class Solution {
public:
	int solve(int i, int j, int n, vector<vector<int>>&triangle) {
		if (i == n - 1)
			return triangle[i][j];
		int bottom = triangle[i][j] + solve(i + 1, j, n, triangle);
		int  bottom_right = triangle[i][j] + solve(i + 1, j + 1, n, triangle);
		return min(bottom, bottom_right);
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		return solve(0, 0, n, triangle);
	}
};


class Solution {
public:

	int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>& dp) {
		if (i == n - 1)
			return triangle[i][j];
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int bottom = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
		int  bottom_right = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);
		return dp[i][j] = min(bottom, bottom_right);
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>>dp(200, vector<int>(200, -1));

		int n = triangle.size();
		return solve(0, 0, n, triangle, dp);
	}
};