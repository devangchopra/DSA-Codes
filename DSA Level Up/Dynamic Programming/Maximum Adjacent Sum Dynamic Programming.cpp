#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

//Bottom up
//Fxn Define : Max Non Adjacent Sum Till a breakpoint\

int fxn(vector<int>&arr) {

	int n = arr.size();
	vector<int>dp(n, 0);

	//Corner cases
	if (n == 1) {
		return max(arr[0], 0);
	}
	if (n == 2) {
		return max(0, max(arr[0], arr[1]));
	}
	//Comparing for 0 if the array contain -ve integers


	dp[0] = max(0, arr[0]);
	dp[1] = max(0, max(arr[0], arr[1]));

	//Recurrence Relation from this point

	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1]
		            , dp[i - 2] + arr[i]);

		//Including or not including the ith element in the final state
	}

	return dp[n - 1];

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