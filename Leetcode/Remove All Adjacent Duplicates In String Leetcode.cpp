class Solution {
public:
	string removeDuplicates(string s) {
		stack<char>st;
		for (auto& i : s) {
			if (st.empty() or st.top() != i) {
				st.push(i);
			}
			else if (st.top() == i) {
				st.pop();
				continue;
			}
		}
		string temp;
		while (st.empty() == false) {
			temp.push_back(st.top());
			st.pop();
		}
		reverse(temp.begin(), temp.end());
		return temp;
	}
};