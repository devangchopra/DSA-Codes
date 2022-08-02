// //Frog 1
// //Brute Force Recursion
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5 + 10;
int h[N];

int fun(ll i) {
	//Defination  : This function basically returns the cost to reach the ith stone

	//Base Case
	if (i == 0)	{
		return 0;
		//First Stone
		// 0 base indexing
	}

	ll cost = INT_MAX;

	//Way 1
	cost = min(cost, fun(i - 1) + abs(h[i] - h[i - 1]));

	//Way 2
	if (i > 1) {
		cost = min(cost, fun(i - 2) + abs(h[i] - h[i - 2]));
	}

	return cost;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;

	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}

	cout << fun(n - 1);
	//0 base indexing
}
// //Time Complexity : Exponential

//-----------------------------------------------------------------------------

//DP Optimization
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N];
int dp[N];

ll fun(ll i) {
	//Defination  : This function basically returns the cost to reach the ith stone

	//Base Case
	if (i == 0)	{
		return 0;
		//First Stone
		// 0 base indexing
	}
	if (dp[i] != -1) {
		return dp[i];
	}

	ll cost = INT_MAX;

	//Way 1
	cost = min(cost, fun(i - 1) + abs(h[i] - h[i - 1]));

	//Way 2
	if (i > 1) {
		cost = min(cost, fun(i - 2) + abs(h[i] - h[i - 2]));
	}

	return dp[i] = cost;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}

	cout << fun(n - 1);
	//0 base indexing
}


//--------------------------------------------------------------------

//Atcoder Submission

#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ll long long int
const ll N = 1e5 + 10;
ll h[N];
ll dp[N];

ll fun(ll i) {
	if (i == 0)	{
		return 0;
	}
	if (dp[i] != -1) {
		return dp[i];
	}
	ll cost = INT_MAX;
	cost = min(cost, fun(i - 1) + abs(h[i] - h[i - 1]));
	if (i > 1) {
		cost = min(cost, fun(i - 2) + abs(h[i] - h[i - 2]));
	}
	return dp[i] = cost;
}
int main() {
	fastio;
	ll n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}
	cout << fun(n - 1);
}