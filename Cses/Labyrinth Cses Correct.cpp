#include <bits/stdc++.h>
using namespace std;
struct cell {
	pair<int, int>pt;
	int dist;
};
char a[1001][1001];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};

bool isValid(int x, int y, int n, int m) {
	if (x<0 or y<0 or x >= n or y >= m) {
		return 0;
	}
	return 1;
}

void printPath(int sx, int sy, int dex, int dey, int n, int m) {

	bool vis[n][m];
	memset(vis, sizeof(vis), 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vis[i][i] << " ";
		} cout << endl;
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		vis[i][j] = 0;
	// 	}
	// }
	queue<cell>Q;
	cell s = {{sx, sy}, 0};
	Q.push(s);
	vis[sx][sy] = 1;
	int parent[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			parent[i][j] = 0;
		}
	}

	while (Q.empty() == false) {

		auto curr = Q.front();
		Q.pop();

		int x = curr.pt.first;
		int y = curr.pt.second;

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (isValid(xx, yy, n, m) and vis[xx][yy] == 0 and a[xx][yy] != '#') {
				vis[xx][yy] = 1;
				cell it = {{xx, yy}, curr.dist + 1};
				parent[xx][yy] = i;
				if (xx == dex and yy == dey) {
					vector<char>ans;
					cout << "YES" << endl;
					cout << it.dist << endl;
					while (!(dex == sx and dey == sy)) {

						int p = parent[dex][dey];
						ans.push_back(dir[p]);
						dex -= dx[p];
						dey -= dy[p];
					}
					reverse(ans.begin(), ans.end());
					for (auto i : ans) {
						cout << i;
					}
					cout << endl;
					return;
				}

				Q.push(it);
			}
		}

	}
	cout << "NO" << endl;
	return;

}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int sx, sy, dex, dey;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'A') {
				sx = i;
				sy = j;
			}
			if (a[i][j] == 'B') {
				dex = i;
				dey = j;
			}
		}
	}
	printPath(sx, sy, dex, dey, n, m);
	return 0;
}