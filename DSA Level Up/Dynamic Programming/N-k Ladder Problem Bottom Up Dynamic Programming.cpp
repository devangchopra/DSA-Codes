#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n , k;
	cin >> n >> k;

	vector<int>dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
			}
		}
	}

	cout << dp[n];

}