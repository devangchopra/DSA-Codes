bool isvalid(int i, int j, int n, int m, int** arr, vector<vector<bool>>& vis) {
	if (i<0 or i >= n or j<0 or j >= m or vis[i][j] == true) {
		return false;
	}
	return true;
}

vector<pair<int, int>>dir = {{ -1, -1}, { -1, 0}, { -1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

void fxn(int** arr, int i, int j, int n, int m, vector<vector<bool>>&vis) {
	if (isvalid(i, j, n, m, arr, vis) == false) {
		return ;
	}
	vis[i][j] = true;
	bool found = false;
	int count = 0;
	for (auto& p : dir) {
		int ni = i + p.first;
		int nj = j + p.second;
		if (isvalid(ni, nj, n, m, arr, vis) and arr[ni][nj] == 1) {
			fxn(arr, ni, nj, n, m, vis);
		}
	}
	return;
}

int getTotalIslands(int** arr, int n, int m) {
	// Write your code here.
	vector<vector<bool>>v(n, vector<bool>(m, false));
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 and v[i][j] == false) {
				fxn(arr, i, j, n, m, v);
				count++;

			}
		}
	}
	return count;
}
