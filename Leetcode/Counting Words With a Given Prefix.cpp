//Done
class Solution {
public:
	int prefixCount(vector<string>& words, string pref) {
		int count = 0;
		for (auto& i : words) {
			bool ans = true;
			for (int j = 0; j < pref.size(); j++) {
				if (j > i.size()) {
					ans = false;
					break;
				}
				if (pref[j] == i[j]) {
					continue;
				}
				else {
					ans = false;
					break;
				}
			}
			if (ans) {
				count++;
			}

		}
		return count;

	}
};