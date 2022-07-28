class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size();
		int m = text2.size();

		int t[n + 1][m + 1];

		//BASE CONDITION
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m ; ++j) {
				if (i == 0 or j == 0) {
					t[i][j] = 0;
				}
			}
		}

		//FILL THE MATRIX
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m ; ++j) {
				if (text1[i - 1] == text2[j - 1]) {
					t[i][j] = 1 + t[i - 1][j - 1];
				}
				else {
					t[i][j] = max(t[i - 1][j], t[i][j - 1]);
				}
			}
		}

		//NOW I HAVE THE MATRIX
		//SAME : i-- , j--
		//DIFF : MAXIMUM : i-1,j , i,j-1

		int i = n, j = m;
		string s = "";
		while (i > 0 and j > 0) {
			if (text1[i - 1] == text2[j - 1]) {
				s.push_back(text1[i - 1]);
				i--;
				j--;
			}
			else {
				if (t[i - 1][j] > t[i][j - 1]) {
					i--;
				}
				else {
					j--;
				}
			}
		}
		reverse(s.begin(), s.end());
		cout << s << endl;

		return t[n][m];
	}
};