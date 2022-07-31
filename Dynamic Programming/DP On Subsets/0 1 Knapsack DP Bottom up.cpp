//0 1 knapsack
#include <bits/stdc++.h>
using namespace std;
int main() {
	int wt[] = {1, 3, 4, 5};
	int val[] = {1, 4, 5, 7};
	int W = 7;

	//check about n and m

	int t[5][8];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 or j == 0) {
				t[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (wt[i - 1] <= j) {
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	int n = wt.size();
	cout << t[n][W];
}






