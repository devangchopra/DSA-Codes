#include<bits/stdc++.h>
using namespace std;

void lcs(string x, string y, int n, int m) {
	int t[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 or j == 0) {
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
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
		}
	}

	string s;

	int i = n, j = m;
	while (i > 0 and j > 0) {
		if (x[i - 1] == y[j - 1]) {
			s.push_back(x[i - 1]);
			i--;
			j--;
		}
		else {
			if (t[i][j - 1] > t[i - 1][j]) {
				j--;
			}
			else {
				i--;
			}
		}
	}

	reverse(s.begin(), s.end());
	cout << s << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string x;
	string y;
	cin >> x >> y;
	lcs(x, y, x.size(), y.size());
}

