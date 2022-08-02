class Solution {
public:
	string reverseOnlyLetters(string s) {

		if (s.size() <= 1) {
			return s;
		}
		int i = 0;
		int j = s.size() - 1;
		while (i <= j) {
			if ((s[i] >= 97 and s[i] <= 122) or (s[i] >= 65 and s[i] <= 90)) {
				if ((s[j] >= 97 and s[j] <= 122) or (s[j] >= 65 and s[j] <= 90)) {
					swap(s[i], s[j]);
					j--;
					i++;
					continue;
				}
				j--;
			}
			else {
				i++;
			}

		}

		return s;
	}
};

