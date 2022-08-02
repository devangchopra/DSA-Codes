class Solution {
public:
	vector<int>nge(vector<int>& arr) {
		stack<int>s;
		s.push(0);
		int n = arr.size();
		vector<int>nge(n);
		//if smaller or greater then push it into the stack
		for (int i = 1; i < n; i++) {
			if (s.empty()) {
				s.push(i);
				continue;
			}
			while (s.empty() == false and s.top() < arr[i]) {
				nge[s.top()] = arr[i];
				s.pop();
			}
			s.push(i);
		}
		while (s.empty() == false) {
			nge[s.top()] = -1;
			s.pop();
		}
		return nge;
	}
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int>mp;
		vector<int>ans = nge(nums2);
		for (int i = 0; i < ans.size(); i++) {
			mp[nums2[i]] = ans[i];
		}
		vector<int>final(nums1.size());
		for (auto& i : nums1) {
			final.push_back(mp[i]);
		}
		return final;
	}
};


#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<int>arr = {1, 2, 3, 4};
	stack<int>s;
	s.push(0);
	vector<int>nge(4);
	//if smaller or greater then push it into the stack
	for (int i = 1; i < 4; i++) {
		if (s.empty()) {
			s.push(i);
			continue;
		}
		while (s.empty() == false and s.top() < arr[i]) {
			nge[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	while (s.empty() == false) {
		nge[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < 4; ++i)
	{
		cout << i << " " << nge[i] << endl;
	}
}