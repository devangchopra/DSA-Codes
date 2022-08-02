#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		if (n == 1) {
			return -1;
		}
		unordered_map<int, pair<int, int>>mp;
		for (int i = 1; i <= n; i++) {
			mp.insert({i, {0, 0}});
		}
		//first : indegree
		//Second : outdegree
		for (auto v : trust) {
			mp[v[0]].second++;
			mp[v[1]].first++;
		}
		set < int, greater<int>>s;
		for (auto i : mp) {
			if (i.second.first != 0 and i.second.second == 0 ) {
				s.insert(i.first);
			}
		}
		if (s.size() == 0) {
			return -1;
		}
		auto it = s.begin();
		if (mp[*it].first != n - 1) {
			return -1;
		}
		return *it;

	}
};
int main() {
	Solution obj;
	int n = 4;
	vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
	int n2 = 2;
	vector<vector<int>> trust2 = {{1, 2}};
	int n3 = 3;
	vector<vector<int>> trust3 = {{1, 2}, {2, 3}};
	cout << obj.findJudge(n3, trust3);
}