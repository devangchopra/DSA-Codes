#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int dp[100005][4];
int n;

int func(int ind, int flag) {

	if (ind == n) return 0;

	if (dp[ind][flag] != -1) return dp[ind][flag];

	int maxi = 0;
	if (flag == 0) {
		maxi = max(maxi, a[ind][1] + func(ind + 1, 1));
		maxi = max(maxi, a[ind][2] + func(ind + 1, 2));
		maxi = max(maxi, a[ind][3] + func(ind + 1, 3));
	}
	else if (flag == 1) {
		maxi = max(maxi, a[ind][2] + func(ind + 1, 2));
		maxi = max(maxi, a[ind][3] + func(ind + 1, 3));
	}
	else if (flag == 2) {
		maxi = max(maxi, a[ind][1] + func(ind + 1, 1));
		maxi = max(maxi, a[ind][3] + func(ind + 1, 3));
	}
	else {
		maxi = max(maxi, a[ind][1] + func(ind + 1, 1));
		maxi = max(maxi, a[ind][2] + func(ind + 1, 2));
	}

	return dp[ind][flag] = maxi;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	memset(dp, -1, sizeof dp);

	cout << func(0, 0);

	return 0;
}