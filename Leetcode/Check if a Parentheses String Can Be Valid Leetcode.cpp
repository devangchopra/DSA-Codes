class Solution {
public:
	bool canBeValid(string s, string locked) {
		int n = s.size();
		if (n & 1) {
			return false;
		}

		//Left to right traversal
		int extra = 0, balance = 0;
		for (int i = 0; i < n; i++) {
			if (locked[i] == '0') {
				extra++;
			}
			else {
				if (s[i] == '(') {
					balance += 1;
				}
				else {
					balance += -1;
				}
				if (balance == -1) {
					balance = 0;
					if (extra == 0) {
						return false;
					}
					extra--;
				}
			}
		}

		//Right to left traversal
		extra = 0, balance = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (locked[i] == '0') {
				extra++;
			}
			else {
				if (s[i] == ')') {
					balance += 1;
				}
				else {
					balance += -1;
				}
				if (balance == -1) {
					balance = 0;
					if (extra == 0) {
						return false;
					}
					extra--;
				}
			}
		}

		return true;

	}
};