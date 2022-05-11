#include <bits/stdc++.h>
bool findWord(string &s, string &w) {
	//	Write your code here.
	bool ans = false;
	istringstream ss(s);
	string curr;

	while (ss >> curr) {
		if (curr == w) {
			ans = true;
			break;
		}
	}
	return ans;
}