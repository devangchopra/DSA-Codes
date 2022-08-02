class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int n = isWater.size();
		int m = isWater[0].size();
		int dist[n][m];
		queue<pair<int, int>>Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isWater[i][j] == 1) {
					dist[i][j] = 0;
					Q.push({i, j});
					continue;

				}
				dist[i][j] = INT_MAX;
			}
		}

		int dx[4] = {0, 0, -1, 1};
		int dy[4] = { -1, 1, 0, 0};
		while (Q.empty() == false) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx >= 0 and xx<n and yy >= 0 and yy < m and dist[xx][yy] == INT_MAX and isWater[xx][yy] == 0) {
					dist[xx][yy] = dist[x][y] + 1;
					//Now this will become source for other
					Q.push({xx, yy});
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << dist[i][j] << " ";
			} cout << endl;
		}

		return isWater;

	}
};