class Solution {
public:

	bool pred(string& s1, string& s2) {

		if (s1.size() != 1 + s2.size()) {
			return false;
		}

		int first = 0;
		int second = 0;

		while (first < s1.size()) {
			if (second < s2.size() and s1[first] == s2[second]) {
				first++;
				second++;
			}
			else {
				first++;
			}
		}

		if (first == s1.size() and second == s2.size()) {
			return true;
		}

		return false;
	}

	static bool comp(string& s1, string& s2) {
		return s1.size() < s2.size();
	}

	int longestStrChain(vector<string>& words) {
		int n = words.size();
		vector<int>dp(n, 1);
		sort(words.begin(), words.end(), comp);
		int max_till_now = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				//Maxi
				if (pred(words[i], words[j]) and 1 + dp[j] > dp[i]) {
					dp[i] = 1 + dp[j];
				}
			}
			if (dp[i] > max_till_now) {
				max_till_now = dp[i];
			}
		}

		return max_till_now;
	}
};