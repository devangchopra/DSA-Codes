//TOP DOWN APPROACH WILL GIVE TLE
//BASE CONDITION : INITIALIZTION
//CHOICE DIAGRAM : FILL THEE MATRIX

class Solution {
public:

	int dp[1050][1050];

	int fxn(string x, string y, int n, int m) {
		if (n == 0 or m == 0) {
			return 0;
		}

		if (dp[n][m] != -1) {
			return dp[n][m];
		}
		if (x[n - 1] == y[m - 1]) {
			return dp[n][m] = 1 + fxn(x, y, n - 1, m - 1);
		}

		return dp[n][m] = max(fxn(x, y, n - 1, m), fxn(x, y, n, m - 1));
	}

	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size();
		int m = text2.size();
		memset(dp, -1, sizeof(dp));
		return fxn(text1, text2, n, m);
	}
};

//SOLUTION : YOU HAVE TO PASS BY REFERNCE THE INPUTS BECAUSE IN EACH CALL COPIES ARE CREATED
/*
However, in each recursive call the function creates a new copy of the string, which causes an O(m) overhead time complexity for each string, where m is the length of the string in each function call.

Best way to surpass this would be to pass by reference instead of pass by value, so that the overhead never happens and all functions use the same string at the same memory.

*/
class Solution {
public:

	int dp[1050][1050];

	int fxn(string& x, string& y, int n, int m) {
		if (n == 0 or m == 0) {
			return 0;
		}

		if (dp[n][m] != -1) {
			return dp[n][m];
		}
		if (x[n - 1] == y[m - 1]) {
			return dp[n][m] = 1 + fxn(x, y, n - 1, m - 1);
		}

		return dp[n][m] = max(fxn(x, y, n - 1, m), fxn(x, y, n, m - 1));
	}

	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size();
		int m = text2.size();
		memset(dp, -1, sizeof(dp));
		return fxn(text1, text2, n, m);
	}
};


//BOTTOM UP
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size();
		int m = text2.size();
		int i[n + 1][m + 1];
		//solution will be stored in nm cell

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m ; ++j) {
				if (i == 0 or j == 0) {
					t[i][j] = 0;
				}
			}
		}

		//choice diagram : fill the matrix

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= m ; ++j) {
				if (x[i - 1] == y[j - 1]) {
					t[i][j] = 1 + t[i - 1][j - 1];
				}
				else {
					t[i][j] = max(t[i][j - 1], t[i - 1][j]);
				}
			}
		}

		return t[n][m];
	}
};


//PRINT THE LCS
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

//LONGEST PALLINDROMIC SUBSEQUENCE
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

//MINIMUM NUMBER OF DELETIONS :
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


		return s.size() - t[n][m];
	}
};