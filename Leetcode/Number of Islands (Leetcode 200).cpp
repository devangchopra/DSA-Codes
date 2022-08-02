#include <bits/stdc++.h>
using namespace std;

class Solution {
	int a[500][500], visited[500][500];
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = { -1, 1, 0, 0};
public:
	void flood_fill(int x, int y, vector<vector<char>>& grid, int n, int m) {
		visited[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 and xx < n and yy >= 0 and yy < m and !visited[xx][yy] and
			        grid[xx][yy] == '1') {
				flood_fill(xx, yy, grid, n, m);
			}
		}
		return;
	}
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int total_count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] and grid[i][j] == '1') {
					cout<<i<<" "<<j<<" "<<endl;
					total_count++;
					flood_fill(i, j, grid, n, m);
				}
			}
		}
		return total_count;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution obj;
	vector<vector<char>> grid = {
		{'1','1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};

	cout<<obj.numIslands(grid);


}


