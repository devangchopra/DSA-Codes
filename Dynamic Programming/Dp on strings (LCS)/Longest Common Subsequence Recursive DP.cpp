#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m) {

	//1.Base Condition
	if (n == 0 or m == 0) {
		return 0;
	}

	//2. Choice Diagram
	if (x[n - 1] == y[m - 1]) {
		return 1 + lcs(x, y, n - 1, m - 1);
	}
	return max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x, y;
	cin >> x >> y;
	cout << "LCS IS" << " " << lcs(x, y, x.size(), y.size());
}


//Leetcode 1143
//Recursive will give TLE
class Solution {
public:
	int lcs(string x, string y, int n, int m) {

		//1.Base Condition
		if (n == 0 or m == 0) {
			return 0;
		}

		//2. Choice Diagram
		if (x[n - 1] == y[m - 1]) {
			return 1 + lcs(x, y, n - 1, m - 1);
		}
		return max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
	}

	int longestCommonSubsequence(string text1, string text2) {
		return lcs(text1, text2, text1.size(), text2.size());

	}
};