#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

//Fxn Definition : Miniumum possible to cost to reach this state

long long fxn(vector<int>&arr, int n, vector<int>& dp) {

	if (n == arr.size() - 1) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	long long ans1 = INT_MAX;
	long long ans2 = INT_MAX;

	if (n + 1 <= arr.size() - 1) {
		ans1 = fxn(arr, n + 1, dp);
	}

	if (n + 2 <= arr.size() - 1) {
		ans2 = fxn(arr, n + 2, dp);
	}

	long long ans = 0;

	if (ans1 > ans2) {
		ans = ans2 + abs(arr[n + 2] - arr[n]);
	}
	else {
		ans = ans1 + abs(arr[n + 1] - arr[n]);
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

	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int>dp(n + 1, -1);
	//For Safety n+1

	cout << fxn(arr, 0, dp);

}