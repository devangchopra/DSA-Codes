#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e5 + 1;
int dp[N];


//Recursive
int fxn(vector<int> &arr, int M) {
	if (M == 0) {
		return 0;
	}
	int ans = INT_MAX, temp = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (M - i >= 0) {
			temp = fxn(arr, M - arr[i]);
			if (temp != -1) {
				ans = min(ans, temp + 1);
			}
		}
	}

	if (ans == INT_MAX) {
		return -1;
	}
	return ans;
}

//DP
int fxn_dp(vector<int> &arr, int M) {
	if (M == 0) {
		return 0;
	}
	if (M < 0) {
		//IMP As a base case
		return -1;
	}
	if (dp[M] != INT_MIN) {
		return dp[M];
	}
	int ans = INT_MAX, temp = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (M - i >= 0) {
			temp = fxn_dp(arr, M - arr[i]);
			if (temp != -1) {
				ans = min(ans, temp + 1);
			}
		}
	}

	if (ans == INT_MAX) {
		return dp[M] = -1;
	}
	return dp[M] = ans;
}





int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>arr;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	int M;
	cin >> M;

	//cout << fxn(arr, M);

	for (int i = 0; i <= M; i++) {
		dp[i] = INT_MIN;
	}

	cout << fxn_dp(arr, M);
}