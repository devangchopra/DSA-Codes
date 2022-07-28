class Solution {
public:
	int minDistance(string word1, string word2) {

		int n = word1.size();
		int m = word2.size();

		int t[n + 1][m + 1];

		//INITIALIZATION

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m ; ++j) {
				if (i == 0  or j == 0) {
					t[i][j] = 0;
				}
			}
		}

		//FILL THE MATRIX

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m ; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					t[i][j] = 1 + t[i - 1][j - 1];
				}
				else {
					t[i][j] = max(t[i - 1][j], t[i][j - 1]);
				}
			}
		}

		int size = t[n][m];

		return (n + m) - 2 * sze;

	}
};