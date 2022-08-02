#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m ;
	cin >> n >> m;
	int a[n][m], distance[n][m];
	queue<pair<int, int>>Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			distance[i][j] = INT_MAX;
			if (a[i][j] == 1 and i == 0) {
				distance[i][j] = 0;
				Q.push({i, j});
			}
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
			if (xx >= 0 and xx<n and yy >= 0 and yy < m
			        and a[xx][yy] == 1 and distance[xx][yy] == INT_MAX) {
				Q.push({xx, yy});
				distance[xx][yy] = distance[x][y] + 1;
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << distance[i][j] << " ";
	// 	} cout << endl;
	// }

	int ans = INT_MAX;

	for (int i = 0; i < m; i++) {
		ans = min(ans, distance[n - 1][i]);
	}

	cout<<ans<<endl;

	return 0;
}