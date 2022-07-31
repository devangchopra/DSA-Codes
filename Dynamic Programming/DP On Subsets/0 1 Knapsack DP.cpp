#include <bits/stdc++.h>
using namespace std;
int t[102][1002];

int knapsack(int wt[], int val[], int W, int n) {
	//Base Case
	if (n == 0 or W == 0) {
		return 0;
	}
	if (t[n][W] != -1) {
		return t[n][W];
	}
	if (wt[n - 1] <= W) {
		return t[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
	}
	// else if (wt[n - 1] > W) {

	// }
	return t[n][W] = knapsack(wt, val, W, n - 1);
}
int main() {
	int wt[] = {1, 3, 4, 5};
	int val[] = {1, 4, 5, 7};
	int W = 7, n = 4;
	memset(t, -1, sizeof(t));
	cout << knapsack(wt, val, W, n) << endl;
}