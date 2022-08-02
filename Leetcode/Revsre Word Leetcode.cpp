class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int st_idx_crr_word = 0, next_idx = 0, i = 0, n = s.size();
		while (i < n) {
			while (i < n and s[i] != ' ') {
				s[next_idx] = s[i];
				next_idx++;
				i++;
			}

			if (st_idx_crr_word < next_idx) {
				//Word hai
				reverse(s.begin() + st_idx_crr_word, s.begin() + next_idx);
				if (next_idx == n) {
					break;
				}
				s[next_idx] = ' ';
				//In between space
				next_idx++;
				st_idx_crr_word = next_idx;
			}
			i++;
		}
		if (next_idx > 0 and s[next_idx - 1] == ' ') {
			next_idx--;
		}
		s.resize(next_idx);
		return s;
	}
};