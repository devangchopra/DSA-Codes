//****Maximal Square Problem

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		t[n][m];
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (i == n - 1 and j == m - 1) {
					t[i][j] = matrix[i][j] - '0';
				}
				else if (i == n - 1) {
					t[i][j] = matrix[i][j] - '0';
				}
				else if (j == m - 1) {
					t[i][j] = matrix[i][j] - '0';
				}
				else {
					if (arr[i][j] == '0') {
						t[i][j] = 0;
					}
					else {
						int mini = min(t[i][j + 1], t[i + 1][j]);
						mini = min(min, t[i + 1][j + 1]);
						t[i][j] = min + 1;
						if (t[i][j] > ans) {
							ans = t[i][j];
						}
					}
				}
			}
		}
		return ans;
	}
};