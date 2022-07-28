class Solution {
public:
	string shortestCommonSupersequence(string x, string y) {
		int n = str1.size();
		int m = str2.size();

		//LCS TABLE
		int t[n + 1][m + 1];

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m ; ++j) {
				if (i == 0 or j == 0) {
					t[i][j] = 0;
				}
			}
		}

		//Initialization

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

		//Now we have the table
		//Move : select the order
		int i = n, j = m;
		string ans = "";
		while (i > 0 and j > 0) {
			if (x[i - 1] == y[j - 1]) {
				ans.push_back(x[i - 1]);
				i--;
				j--;
			}
			else if (t[i - 1][j] > t[i][j - 1]) {
				//x movement
				ans.push_back(x[i - 1]);
				i--;
			}
			else {
				ans, push_back(y[j - 1]);
				j--;
			}
		}

		while (i > 0) {
			ans.push_back(x[i - 1]);
			i--;
		}

		while (j > 0) {
			ans.push_back(y[j - 1]);
			j--;
		}

		reverse(ans.begin(),ans.end());
		return ans;
	}
};