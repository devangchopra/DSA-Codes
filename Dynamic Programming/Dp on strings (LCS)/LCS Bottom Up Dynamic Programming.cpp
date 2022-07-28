#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

//Bottom Up
int lcs(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				int opn1 = dp[i - 1][j];
				int opn2 = dp[i][j - 1];
				dp[i][j] = max(opn2, opn1);
			}
		}
	}

	//For Printing
	string ans = "";
	int i = n, j = m;
	while (i != 0 and j != 0) {
		//Not Equal Case
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			ans.push_back(s1[i - 1]);
			i--;
			j--;
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return dp[n][m];
}



int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;

	cout << lcs(s1, s2);
}