#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int arr[], int sum, int n) {
	bool t[n + 1][sum + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
			{
				t[i][j] = false;
			}
			if (j == 0) {
				t[i][j] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) {
				t[i][j] = (t[i - 1][j - arr[i - 1]] or t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][sum];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {1, 5, 11, 7}, sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += arr[i];
	}
	if (sum % 2 != 0) {
		cout << "False" << endl;

	}
	else {
		if (subset_sum(arr, sum / 2, 4)) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}
	return 0;
}