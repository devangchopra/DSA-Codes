class Solution {
public:


	int longestPalindromeSubseq(string s) {
		string x = s;
		reverse(s.begin(), s.end());
		string y = s;

		int n = x.size();
		int m = n;

		int t[n + 1][m + 1];

		//BASE CASE
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
				if (x[i - 1] == y[j - 1]) {
					t[i][j] = 1 + t[i - 1][j - 1];
				}
				else {
					t[i][j] = max(t[i - 1][j], t[i][j - 1]);
				}
			}
		}

		//FOR PRINTING
		int i = n, j = m;
		string ans = "";
		while (i > 0 and j > 0) {
			if (x[i - 1] == y[j - 1]) {
				ans.push_back(x[i - 1]);
				i--;
				j--;
			}
			else if (t[i - 1][j] > t[i][j - 1]) {
				i--;
			}
			else {
				j--;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;

		return t[n][m];
	}
};