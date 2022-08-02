#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


//DP Array State Denote : Length of Longest Increasing Subsequence Ending at arr[i]

int fxn(vector<int>&arr) {
	int n = arr.size();
	if (n == 1) {
		return 1;
	}
	vector<int>dp(n , 1);

	int ans = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], 1 + dp[j]);
				ans = max(ans, dp[i]);
			}
		}
	}
	return ans;
}

int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;

	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << fxn(arr);

}