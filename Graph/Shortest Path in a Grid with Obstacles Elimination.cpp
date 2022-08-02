#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int shortestPath(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> visited(n, vector<int>(m, 0));
		queue<vector<int>>Q;
		int dx[] = { -1, 0, 1, 0 };
		int dy[] = { 0, 1, 0, -1 };
		Q.push({0, 0, 0});
		visited[0][0] = 1;
		int count = 0;
		while (Q.size() != 0) {
			count++;
			auto p = Q.front();
			Q.pop();
			int x = p[0];
			int y = p[1];
			int cd = p[2];
			cout<<grid[x][y]<<" ";
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx >= 0 and xx<n and yy >= 0 and yy < m and visited[xx][yy] == 0 and grid[xx][yy] != 1) {
					visited[xx][yy] = 1;
					Q.push({xx, yy, cd + 1});
					if (xx == n - 1 and yy == m - 1) {
						return cd + 1;
					}
				}
			}
		}
		return count;

	}
};
int main() {
	Solution obj;
	vector<vector<int>>grid = { { 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};
	vector<vector<int>>grid2 = {{10, 20, 1, 30}, {1,40, 50, 60}, {70, 80, 90,100}};
	cout << obj.shortestPath(grid2);
}