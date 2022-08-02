//Could Combione case 2 and case 3
class Solution {
public:
	bool detectCapitalUse(string word) {
		bool allsmall = true;
		for (auto& i : word) {
			if (!(i >= 97 and i <= 122)) {
				allsmall = false;
				break;
			}
		}
		if (allsmall) {
			return true;
		}
		bool allcaps = true;
		for (auto&i : word) {
			if (!(i >= 65 and i <= 90)) {
				allcaps = false;
				break;
			}
		}
		if (allcaps) {
			return true;
		}
		if (word[0] >= 65 and word[0] <= 90) {
			bool restSmall = true;
			for (int i = 1; i < word.size(); i++) {
				if (!(word[i] >= 97 and word[i] <= 122)) {
					restSmall = false;
					break;
				}
			}
			return restSmall;
		}
		return false;
	}
};