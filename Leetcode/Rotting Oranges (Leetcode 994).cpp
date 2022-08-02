#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int dist[n][m];
		bool already_ok = true;
		queue<pair<int, int>>Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					already_ok = false;
				}
				dist[i][j] = INT_MAX;
				if (grid[i][j] == 2) {
					Q.push({i, j});
					dist[i][j] = 0;
				}
				if (grid[i][j] == 0) {
					dist[i][j] = INT_MIN;
				}
			}
		}
		if (already_ok) {
			return 0;
		}
		int dx[4] = {0, 0, -1, 1};
		int dy[4] = {1, -1, 0, 0};
		while (Q.empty() == false) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx >= 0 and xx<n and yy >= 0 and yy < m and dist[xx][yy] == INT_MAX
				        and grid[xx][yy] == 1) {
					dist[xx][yy] = dist[x][y] + 1;
					//Now this would eventually become my source
					Q.push({xx, yy});
				}
			}

		}

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		cout << dist[i][j] << " ";
		// 	} cout << endl;
		// }

		bool x = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] == INT_MAX) {
					x = true;
					break;
				}
			}
		}
		if (x) {
			return -1;
		}

		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] != INT_MAX) {
					ans = max(ans, dist[i][j]);
				}
			}
		}
		return ans;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution obj;
	vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
	vector<vector<int>> grid2 = {{0}};
	cout << obj.orangesRotting(grid2) << endl;



	return 0;
}
