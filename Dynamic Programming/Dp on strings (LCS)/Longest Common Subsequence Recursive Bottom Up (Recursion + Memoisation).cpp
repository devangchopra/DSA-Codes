#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];

int lcs(string x, string y, int n, int m) {

	//1.Base Condition
	if (n == 0 or m == 0) {
		return 0;
	}
	if (t[n][m] != -1) {
		return t[n][m];
	}

	//Storage and check before the calls

	//2. Choice Diagram
	if (x[n - 1] == y[m - 1]) {
		return t[n][m] = 1 + lcs(x, y, n - 1, m - 1);
	}
	return t[n][m] =  max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	memset(t, -1, sizeof(t));
	string x, y;
	cin >> x >> y;

	cout << "LCS IS " << " " << lcs(x, y, x.size(), y.size());
	return 0;
}