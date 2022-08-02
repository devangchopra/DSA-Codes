class Solution {
public:
	bool areOccurrencesEqual(string s) {

		unordered_map<char, int>m;
		for (autp c : s)
			m[c]++;
		bool x = true;
		int t = m[s[0]];
		for (auto p : m)
		{
			if (p.second != t)
			{
				x = false;
				break;
			}
		}

		return x;

	}
};