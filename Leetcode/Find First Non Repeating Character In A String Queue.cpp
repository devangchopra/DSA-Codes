#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string S) {
	queue<char>q;
	unordered_map<char, int>m;
	vector<char>v;
	for (auto& i : S) {
		m[i]++;
		q.push(i);

		while (q.empty() == false) {
			if (m[q.front()] > 1) {
				q.pop();
			}
			else {
				v.push_back(q.front());
				break;
			}

		}
		if (q.empty() == true) {
			v.push_back('0');
		}
	}
	return v;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string S = "aabcbcd";
	vector<char>ans = FindFirstNonRepeatingCharacter(S);
	for (auto& i : ans) {
		cout << i << " ";
	}


}