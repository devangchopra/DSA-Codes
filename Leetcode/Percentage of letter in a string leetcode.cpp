class Solution {
public:
	int percentageLetter(string s, char letter) {
		int n = s.size();
		int x = 0;
		for (auto& i : s) {
			if (i == letter) {
				x++;
			}
		}
		return (x*1.0/ n*1.0)*100;
	}
};