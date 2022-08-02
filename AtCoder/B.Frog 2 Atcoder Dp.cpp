#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ll long long int
const ll N = 1e5 + 10;
ll h[N];
ll dp[N];
int k = 0;


ll fun(ll i) {
	if (i == 0)	{
		return 0;
	}
	if (dp[i] != -1) {
		return dp[i];
	}
	ll cost = INT_MAX;
	for (int j = 1; j <= k; j++) {
		if ((i - j) >= 0) {
			cost = min(cost, fun(i - j) + abs(h[i] - h[i - j]));
		}
	}
	return dp[i] = cost;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	ll n;
	cin >> n;
	int ki;
	cin >> ki;
	k = ki;
	memset(dp, -1, sizeof(dp));
	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}
	cout << fun(n - 1);
}