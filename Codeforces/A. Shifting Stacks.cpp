#include <bits/stdc++.h>
using namespace std;
void fun() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	long long sum = 0, need = 0;
	for (int i = 0; i < n; i++) {
		need += i;
		sum += a[i];
		if (sum < need) {
			cout << "no" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		fun();
	}
	return 0;
}