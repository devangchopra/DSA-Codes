#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


//Function Definition : Number of bsts with i

int fxn(int n, vector<int>& dp) {
	if (n == 0 or n == 1) {
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		int x = fxn(i - 1, dp);
		//Left Subtree Ways
		int y = fxn(n - i, dp);
		ans += x * y;
	}

	return dp[n] = ans;
}


int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int>dp(n + 1, -1);
	cout << fxn(n, dp) << endl;
}