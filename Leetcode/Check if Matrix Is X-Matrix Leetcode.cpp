class Solution {
public:
	bool checkXMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int i = 0, j = 0;
		//Diagnol 1
		while (i < n and j < n) {
			if (grid[i][j] == 0) {
				return false;
			}
			i++;
			j++;
		}
		//Daignol 2
		i = 0, j = n - 1;
		while (i<n and j >= 0) {
			if (grid[i][j] == 0) {
				return false;
			}
			grid[i][j] = 0;
			i++;
			j--;
		}
		i = 0, j = 0;
		while (i < n and j < n) {
			grid[i][j] = 0;
			i++;
			j++;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m ; ++j) {
				cout << grid[i][j] << " ";
			} cout << endl;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m ; ++j) {
				if (grid[i][j] != 0) {
					return false;
				}
			}
		}

		return true;
	}
};