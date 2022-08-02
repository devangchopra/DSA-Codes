class Solution {
public:
	int lenLCS(string word1, string word2, int n, int m, vector<vector<int>>& dp) {
		if (n == 0 or m == 0) {
			return 0;
		}
		if (dp[n][m] != -1) {
			return dp[n][m];
		}
		if (word1[n - 1] == word2[m - 1]) {
			return dp[n][m] = 1 + lenLCS(word1, word2, n - 1, m - 1, dp);
		}
		return dp[n][m] = max(lenLCS(word1, word2, n - 1, m, dp), lenLCS(word1, word2, n, m - 1, dp));
	}
	int minDistance(string word1, string word2) {
		//LCS;

		int n = word1.size();
		int m = word2.size();
		vector<vector<int>>dp(600, vector<int>(600, -1));
		int lenLCSs = lenLCS(word1, word2, n, m, dp);
		return m + n - 2 * lenLCSs;
	}
};