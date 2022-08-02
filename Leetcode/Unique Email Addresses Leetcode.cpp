class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string>st;
		for (auto s : emails) {
			int pos = s.find('@');
			string temp;
			for (int i = 0; i < pos; i++) {
				if (s[i] == '+') {
					break;
				}
				if (s[i] == '.') {
					continue;
				}
				temp.push_back(s[i]);
			}
			for (int i = pos; i < s.size(); i++) {
				temp.push_back(s[i]);
			}
			st.insert(temp);
		}
		return st.size();

	}
};