#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string temp = "abcdefghijklmnopqrstuvwxyz";

	vector<int>a(26);
	for (auto& i : a) {
		cin >> i;
	}

	string ans = " ";
	for (auto& i : a) {
		ans.push_back(temp[i - 1]);
	}
	cout << ans << endl;
	return 0;
}