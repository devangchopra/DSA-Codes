#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m) {
	int t[n + 1][m + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				t[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i - 1] == y[j - 1]) {
				t[i][j] = 1 + t[i - 1][j - 1];
			}
			else {
				t[i][j] = 0;
			}
		}
	}

	int ans = INT_MIN;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			ans = max(ans, t[i][j]);
		}
	}

	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string x, y;
	cin >> x >> y;

	int n = x.size(), m = y.size();

	cout << "Longest Common Substring is" << " " << lcs(x, y, n, m);
}