#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = {146, 467, 678, 899};
	int n = 4, x = 46;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 100 == x or arr[i] / 10 == x) {
			cout << arr[i] << " ";
		}
	}

}
