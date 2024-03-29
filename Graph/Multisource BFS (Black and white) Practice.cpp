#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n][m], dist[n][m];
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = { -1, 1, 0, 0};
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			dist[i][j] = INT_MAX;
			if (a[i][j] == 1) {
				//White cell
				Q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 and xx<n and yy >= 0 and yy < m and dist[xx][yy] == INT_MAX) {
				Q.push({xx, yy});
				dist[xx][yy] = dist[x][y] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		} cout << '\n';
	}

	return 0;

}