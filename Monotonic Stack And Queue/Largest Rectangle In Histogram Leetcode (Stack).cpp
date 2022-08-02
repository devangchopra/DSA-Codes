#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n == 1) {
			return heights[0];
		}
		//now we have to calculate left and right limits
		vector<int>left(n), right(n);
		stack<int>s;

		//Left to right
		for (int i = 0; i < n; i++) {
			if (s.empty()) {
				left[i] = 0;
				s.push(i);
			}
			else {
				while (!s.empty() and heights[s.top()] >= heights[i]) {
					s.pop();
				}
				left[i] = s.empty() ? 0 : s.top() + 1;
				s.push(i);
			}
		}

		while (!s.empty()) {
			s.pop();
		}

		//Right to left
		for (int i = n - 1; i >= 0; i--) {
			if (s.empty()) {
				right[i] = n - 1;
				s.push(i);
			}
			else {
				while (!s.empty() and heights[s.top()] >= heights[i]) {
					s.pop();
				}
				right[i] = s.empty() ? n - 1 : s.top() - 1;
				s.push(i);
			}
		}

		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			ans = max(ans, (right[i] - left[i] + 1) * heights[i]);
		}
		return ans;

	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	vector<int>v = {2, 1, 5, 6, 2, 3};
	cout<<obj.largestRectangleArea(v);
}