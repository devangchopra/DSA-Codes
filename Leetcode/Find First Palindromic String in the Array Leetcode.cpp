class Solution {
public:
	bool isp(string x) {
		string r = x;
		reverse(x.begin(), x.end());
		if (x == r) {
			return true;
		}
		return false;
	}
	string firstPalindrome(vector<string>& words) {
		string ans = "";
		for (auto& i : words) {
			if (isp(i)) {
				ans = i;
				break;
			}
		}
		return ans;
	}
};