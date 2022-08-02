#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;

	int stock = n;
	int ans = 0;
	int i = 1;
	while (stock) {
		if (i % m == 0) {
			stock++;
		}
		ans++;
		stock--;
		i++;
	}
	cout << ans << endl;

	return 0;
}