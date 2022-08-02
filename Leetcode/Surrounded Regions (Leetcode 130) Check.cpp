#include <bits/stdc++.h>
using namespace std;

class Solution {
	int visited[500][500];
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = { -1, 1, 0, 0};
public:
	void flood_fill(int x, int y, vector<vector<char>>& board, int n, int m) {
		visited[x][y] = 1;
		bool x = false;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 1 and xx < n - 1 and yy >= 1 and yy < m - 1 and !visited[xx][yy] and
			        board[xx][yy] == 'O') {
				x=true;
				flood_fill(xx, yy, board, n, m);
			}
		}
		if(x){
			board[x][y] = 'X';
		}		
		return;
	}
	void solve(vector<vector<char>>& board) {
		int n = board.size();
		int m = board[0].size();

		for(int i=1;i<n-1;i++){
			for(int j=1;j<m-1;j++){
				if(visited[i][j]==0 and board[i][j]=='O'){
					flood_fill(i,j,board,n,m);
				}
			}
		}
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution obj;
	vector<vector<char>> board1 = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}
	};
	vector<vector<char>> board = {
		{'O','O'},
		{'O','O'}
		
	};

	obj.solve(board);

	for (auto v : board) {
		for (auto i : v) {
			cout << i << " ";
		} cout << endl;
	}
	return 0;
}