class Solution {
public:
	vector<string> cellsInRange(string s) {
		string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		vector<string>ans;
		for (char i = s[0]; i <= s[3]; i++) {
			string temp = "";
			temp.push_back(i);
			for (int j = s[1]; j <= s[4]; j++) {
				temp.push_back(j);
                ans.push_back(temp);
                temp.pop_back();
            }
		}
		return ans;
	}
};