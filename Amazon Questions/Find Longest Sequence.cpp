//This solution will pass only 10/11 test cases
//Reason : maybe dp


bool isInValid(int x, int y, int n) {
	return ((x < 0) || (y < 0) || (x >= n) || (y >= n));
}


void findPath(vector<vector<int>> &grid, int x, int y, int* temp, vector<vector<bool>> &visited, int n) {
	if (isInValid(x, y, n)) return;
	if (visited[x][y]) return;
	*temp = *temp + 1;
	visited[x][y] = true;
	int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
	for (int i = 0; i < 4; i++) {
		int dx = x + d[i][0], dy = y + d[i][1];
		if (!isInValid(dx, dy, n) && !visited[dx][dy] && (grid[x][y] + 1 == grid[dx][dy])) {
			findPath(grid, dx, dy, temp, visited, n);
		}
	}
	visited[x][y] = false;
}



int findLongestOverAll(vector<vector<int>> &grid, int n) {
	// Write your code here.
	int maxLen = 0;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = 0;
			findPath(grid, i, j, &temp, visited, n);
			if (temp > maxLen) {
				maxLen = temp;
			}
		}
	}
	return maxLen;

}



//DP Solution :: Optimal
int dfs(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& mat, int n) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int best = 0;
	vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
	for (const auto &dx : dirs) {
		auto di = dx.first;
		auto  dj = dx.second;
		int ni = i + di;
		int nj = j + dj;
		if (0 <= ni && ni < n && 0 <= nj && nj < n && mat[ni][nj] == 1 + mat[i][j]) {
			best = max(best, dfs(ni, nj, dp, mat, n));
		}
	}

	return dp[i][j] = 1 + best;
}


int findLongestOverAll(vector<vector<int>> &mat, int n) {
	// Write your code here.
	int res = 0;
	vector<vector<int>> dp(n, vector<int>(n, -1));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res = max(res, dfs(i, j, dp, mat, n));
		}
	}

	return res;
}