#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 100;
int arr[N];

int fxn(int n, int k) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		//Handling the n-i < 0 case
		return 0;
	}

	int ans = 0;

	for (int i = 1; i <= k; i++) {
		ans += fxn(n - i, k);
	}

	return ans;
}


int fxn_dp(int n, int k) {
	if (n == 0) {
		return 1;
	}

	if (n < 0) {
		//Handling the n-i < 0 case
		return 0;
	}

	if (arr[n] != -1) {
		return arr[n];
	}


	int ans = 0;

	for (int i = 1; i <= k; i++) {
		ans += fxn_dp(n - i, k);
	}

	return arr[n] = ans;
}



int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	//Recursive
	//cout << fxn(n, k) << endl;

	//Top Down
	memset(arr, -1, sizeof(arr));

	cout << fxn_dp(n, k) << endl;


}