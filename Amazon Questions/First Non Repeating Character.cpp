#include <bits/stdc++.h>
char firstNonRepeatingCharacter(string str) {
	// Write your code here
	unordered_map<char, vector<int>>m;
	for (int i = 0; i < str.size(); i++) {
		m[str[i]].push_back(i);
	}
	char c = '\0';
	for (auto& i : str) {
		if (m[i].size() == 1) {
			c = i;
			break;
		}
	}
	if (c == '\0') {
		return str[0];
	}
	return c;

}
