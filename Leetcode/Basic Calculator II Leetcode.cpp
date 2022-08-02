class Solution {
public:
	int calculate(string s) {
		int n = s.size();
		int current_number = 0;
		char operation = '+';

		stack<int>st;

		for (int i = 0; i < n; i++) {
			char currentchar = s[i];

			if (isdigit(currentchar)) {
				current_number = (current_number * 10) + (currentchar - '0');
			}

			if (!isdigit(currentchar) and !iswspace(currentchar) or i == n - 1) {
				if (operation == '+') {
					st.push(current_number);
				}
				else if (operation == '-') {
					st.push(-current_number);
				}
				else if (operation == '*') {
					int t = st.top();
					st.pop();
					st.push(t * current_number);
				}
				else {
					int t = st.top();
					st.pop();
					st.push(t / current_number);
				}
				operation = currentchar;
				current_number = 0;
			}
		}

		int result = 0;
		while (st.empty() == false) {
			result += st.top();
			st.pop();
		}
		return result;
	}
};