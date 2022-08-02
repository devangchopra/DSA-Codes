class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		if (n == 1) {
			return 1;
		}
		vector < int>v(n + 1, 0);
		for (auto& i : trust) {
			v[i[0]] = INT_MAX;
			if (v[i[1]] != INT_MAX) {
				v[i[1]]++;
			}
		}
		for (int i = 0; i <= n; ++i) {
			if (v[i] != INT_MAX) {
				if (v[i] == n - 1) {
					return i;
				}
			}
		}
		return -1;
	}
};