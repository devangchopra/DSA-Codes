
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		unordered_map<string, char>mp;
		string alphabet = "abcdefghijklmnopqrstuvwxyz", ans = "";
		int index = 0;
		istringstream ss(s);
		string temp;
		while (ss >> temp) {
			if (mp.find(temp) == mp.end()) {
				mp.insert({temp, alphabet[index]});
				index++;
			}
			ans.push_back(mp[temp]);
		}
		cout << ans << endl;
		unordered_map<char, char>mpp;
		index = 0;
		string vans;
		for (auto& i : pattern) {
			if (mpp.find(i) == mpp.end()) {
				mpp.insert({i, alphabet[index]});
                index++;
			}
			vans.push_back(mpp[i]);
		}
		cout << vans << endl;
		if (ans == vans) {
			return true;
		}
		return false;
	}
};

