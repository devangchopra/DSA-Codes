#include <bits/stdc++.h>
using namespace std;
bool t[1005][1005];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[] = {2, 3, 7, 8, 10};
	int sum = 11;
	int n = 5;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < sum + 1; j++) {
			if (i == 0) {
				t[i][j] = false;
			}
			if (j == 0) {
				t[i][j] = true;
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1 ;j < sum + 1; j++) {
			if (arr[i - 1] <= j) {
				t[i][j] = (t[i][j - arr[i - 1]] or t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}

	cout << endl <<	 t[n][sum];



	return 0;
}