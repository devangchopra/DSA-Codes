#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

void fun(ll cn) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n == 1) {
		cout << "Case #" << cn << ":" << " " << 0 << endl;
		return;
	}
	ll ans = 0;

	ll lastIndex = n - 1;
	vector<pair<int, int>>v;
	char change = '\0';
	pair<int, int>p;
	bool is_x_coming = false;
	bool is_o_coming = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (s[i] == 'X') {
			change = 'X';
			is_x_coming = true;
			if (is_o_coming) {
				is_o_coming = false;
				p.second = i;
				v.push_back(p);
				p.first = i;
			}
			else {
				p.first = i;
			}
		}
		else if (s[i] == 'O') {
			change = 'O';
			is_o_coming = true;
			if (is_x_coming) {
				is_x_coming = false;
				p.second = i;
				v.push_back(p);
				p.first = i;

			}
			else {
				p.first = i;
			}
		}
	}


	for (auto i : v) {
		int start = i.first;
		int end = i.second;
		int diff = (end - start) + 1;
		for (int i = diff; i <= lastIndex; i++) {

			int temp = end;
			int counter = i - 1;
			for (int j = temp; j <= lastIndex; j++) {
				if (j - counter <= start and j - counter >= 0) {
					ans++;
				}
			}
		}
		ans++;
	}

	cout << "Case #" << cn << ":" << " " << ans%mod << endl;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	ll t;
	cin >> t;
	ll cn = 0;
	while (t--) {
		cn++;
		fun(cn);
	}

	return 0;
}