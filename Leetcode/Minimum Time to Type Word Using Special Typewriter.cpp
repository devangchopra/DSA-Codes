class Solution {
public:
	int minTimeToType(string word) {

		//a->1
		//z->26
		unordered_map<char, int>m;
		string s = "abcdefghijklmnopqrstuvwxyz";
		int c = 1;
		for (auto i : s)
		{
			m[i] = c;
			c++;
		}

		//number of moves
		int ans = word.size();
		int s1 = 1;
		int s2 = m[word[0]];

		if (s1 > s2)
		{
			ans+=min(abs(s1 - s2), abs((s2 + 26) - s1));
		}
		else if (s1 < s2)
		{
			ans+=min(abs(s1 - s2), abs((s1 + 26) - s2));
		}


		for (int i = 0; i < word.size() - 1; i++)
		{

			int s1 = m[word[i]];
			int s2 = m[word[i + 1]];
			int moves = 0;
			if (s1 > s2)
			{
				moves = min(abs(s1 - s2), abs((s2 + 26) - s1));
			}
			else if (s1 < s2)
			{
				moves = min(abs(s1 - s2), abs((s1 + 26) - s2));
			}
			ans += moves;

		}

		return ans;

	}
};

