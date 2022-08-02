#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 100;
int dp[N];

//Defination of this function
//minimum number of jumps to reach n

int fxn(vector<int>&arr, int n, int i) {

	if (i == n - 1) {
		return 0;
	}

	if (i >= n) {
		return INT_MAX;
	}
	if (dp[i] != -1) return dp[i];

	int ans = INT_MAX;

	for (int j = 1; j <= arr[i]; j++) {

		int next_cell = j + i;
		int temp = fxn(arr, n, next_cell);
		if (temp != INT_MAX) {
			ans = min(ans, temp + 1);
		}
	}

	return dp[i] = ans;
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
	memset(dp, -1, sizeof(dp));

	cout << fxn(arr, n, 0);
}