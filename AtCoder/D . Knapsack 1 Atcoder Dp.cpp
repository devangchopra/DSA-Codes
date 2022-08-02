//Error on acceptance on Atcoder
//But gets accepted on gfg

#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int p = 100005, q = 105 ;
int t[p][q];

int fxn_recursive(int W, vector<int>weight, vector<int>value, int N) {

	//Base Condition
	if (N == 0 or W == 0) {
		return 0;
	}

	//Choice Diagram
	if (weight[N - 1] > W) {
		return fxn_recursive(W, weight, value, N - 1);
	}

	//Include or not include
	return max((value[N - 1] + fxn_recursive(W - weight[N - 1], weight, value, N - 1)),
	           (fxn_recursive(W, weight, value, N - 1)));

}


int fxn_dp(int W, vector<int>weight, vector<int>value, int N) {

	//Base Condition
	if (N == 0 or W == 0) {
		return 0;
	}

	//Check
	if (t[W][N] != -1) {
		return t[W][N];
	}

	//Choice Diagram
	if (weight[N - 1] > W) {
		return t[W][N] = fxn_dp(W, weight, value, N - 1);
	}

	//Include or not include
	return t[W][N] = max((value[N - 1] + fxn_dp(W - weight[N - 1], weight, value, N - 1)),
	                     (fxn_dp(W, weight, value, N - 1)));

}

int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	memset(t, -1, sizeof(t));
	int N, W;
	cin >> N >> W;
	vector<int>weight;
	vector<int>value;
	int x, y;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		weight.push_back(x);
		value.push_back(y);
	}
	// int ans = fxn_recursive(W, weight, value, N);
	// cout << ans << endl;
	fxn_dp(W, weight, value, N);
	cout << t[W][N] << endl;

}



//Gfg Accepted
int fxn_dp(int W, vector<int>weight, vector<int>value, int N) {

	//Base Condition
	if (N == 0 or W == 0) {
		return 0;
	}

	//Check
	if (t[W][N] != -1) {
		return t[W][N];
	}

	//Choice Diagram
	if (weight[N - 1] > W) {
		return t[W][N] = fxn_dp(W, weight, value, N - 1);
	}

	//Include or not include
	return t[W][N] = max((value[N - 1] + fxn_dp(W - weight[N - 1], weight, value, N - 1)),
	                     (fxn_dp(W, weight, value, N - 1)));

}