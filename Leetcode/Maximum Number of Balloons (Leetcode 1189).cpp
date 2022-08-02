class Solution {
public:
	int maxNumberOfBalloons(string text) {
		unordered_map<char, int>mp;
		for (auto& i : text) {
			mp[i]++;
		}
		int count = 0;
		while (mp['b'] >= 1 and mp['a'] >= 1 and mp['l'] >= 2 and mp['o'] >= 2 and mp['n'] >= 1) {
			count++;
			mp['b']--;
			mp['a']--;
			mp['l'] = mp['l'] - 2;
			mp['o'] = mp['o'] - 2;
			mp['n'] = mp['n'] - 1;
		}
		return count << endl;

	}
};