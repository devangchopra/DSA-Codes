#include <bits/stdc++.h>
using namespace std;

int longBinSubs(string s) {
	//Write your code here
	int ans = INT_MIN;
	char prev = s[0];
	int temp = 1;
	bool nochange = true;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != prev) {
			nochange = false;
			temp++;
			prev = s[i];
		}
		else if (s[i] == prev) {
			ans = max(ans, temp);
			temp = 1;
			prev = s[i];
		}
	}

	if (temp != 1) {
		ans = max(ans, temp);
	}

	if (ans == INT_MIN or nochange) {
		return -1;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s = "11111111";
	cout << longBinSubs(s) << endl;
}