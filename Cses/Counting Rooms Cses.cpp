#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char a[N][N];
int visited[N][N];
int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 and xx<n and yy >= 0 and yy < m and visited[xx][yy] == 0 and a[xx][yy] == '.') {
			dfs(xx, yy);
		}
	}
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 and a[i][j] == '.') {
				dfs(i, j);
				count++;
			}

		}
	}

	cout << count << endl;

	return 0;
}