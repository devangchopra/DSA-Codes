#include <bits/stdc++.h>
using namespace std;

void fun() {
	int n, s;
	cin >> n >> s;
	if (n == 1) {
		cout << s << endl;
		return;
	}
	else if (s == 1) {
		cout << 0 << endl;
		return;
	}
	else {
		int ans = 0;
		if (n % 2 == 0) {
			ans = (s / ((n / 2) + 1));
			//Even case
		}
		else {
			ans = (s / (round(n / (2 * 1.0))));
		}
		cout<<ans<<endl;
	}
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