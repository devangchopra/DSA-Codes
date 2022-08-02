#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N][N], visited[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int color_cnt[100];

void flood_fill(int x, int y, int color) {
	a[x][y] = color;
	color_cnt[color]++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 and xx<n and yy >= 0 and yy < m and !visited[xx][yy] and a[xx][yy] == 1) {
			flood_fill(xx, yy, color);
		}
	}
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	//Color It
	int color = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 and visited[i][j] == 0) {
				color++;
				flood_fill(i, j, color);
			}
		}
	}

	//Maximize by iterating over all
	int largest = INT_MIN;
	for (int i = 1; i <= color; i++) {
		largest = max(largest, color_cnt[i]);
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				set<int>s;
				//Will contain unique elements
				//Go to all nbrs and check for the unique colours
				//Include them in the set
				for (int k = 0; k < 4; k++) {
					int xx = i + dx[k];
					int yy = j + dy[k];

					if (xx >= 0 and xx<n and yy >= 0 and yy < n) {
						s.insert(a[xx][yy]);
						//Already coloured honge if 1
						//Else 0
					}
				}

				//Now include their frequency from color_cnt
				int temp = 1;
				for (auto i : s) {
					temp += color_cnt[i];
				}
				largest = max(largest, temp);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		} cout << endl;
	}

	cout << endl << "This is largest" << " " << largest << endl;



	return 0;
}