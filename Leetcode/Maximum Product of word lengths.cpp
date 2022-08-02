class Solution {
public:
	int maxProduct(vector<string>& words) {
		int ans = 0;
		int n = words.size();
		for (int i = 0; i < n; i++) {
			unordered_set<char>s;
			for (auto& j : words[i]) {
				s.insert(j);
			}
			int x = words[i].size();
			for (int j = i + 1; j < n; j++) {
				int temp = 0;
				bool canbe = true;
				for (auto& c : words[j]) {
					if (s.find(c) != s.end()) {
						canbe = false;
						break;
					}
				}
				if (canbe) {
					temp = x * words[j].size();
				}
				ans = max(ans, temp);
			}
		}
		return ans;
	}
};