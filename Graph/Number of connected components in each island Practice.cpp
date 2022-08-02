#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N][N], visited[N][N];
int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int flood_fill(int x, int y,int color) {
	a[x][y]=color;
	visited[x][y] = 1; 
	int size = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 and xx < n and yy >= 0 and yy < m and a[xx][yy] == 1 and visited[xx][yy]==0) {
			size += flood_fill(xx, yy,color);
		}
	}
	return size;
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

	int color = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 and !visited[i][j]) {
				color++;
				int size = flood_fill(i, j,color);
				cout<<"Component"<<" "<<color<<" "<<size<<endl;
			}
		}
	}

	cout << "Final Matrix" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		} cout << endl;
	}


	return 0;
}