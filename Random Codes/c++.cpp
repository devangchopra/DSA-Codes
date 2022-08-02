
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
// 	vector<int> findOriginalArray(vector<int>& changed) {
// 		int n = changed.size();
// 		if (n % 2 != 0 or n <= 1) {
// 			return {};
// 		}
// 		multiset<int>s;
// 		multimap<int, int>mp;
// 		for (auto& i : changed) {
// 			s.insert(i);
// 		}
// 		sort(changed.begin(), changed.end());
// 		bool are_all_zero = true;
// 		for (int i = 0; i < n; i++) {
// 			mp.insert({changed[i], changed[i] * 2});
// 			if (changed[i] != 0) {
// 				are_all_zero = false;
// 			}
// 		}
// 		vector<int>ans;
// 		if (are_all_zero) {
// 			for (int i = 0; i < n / 2; i++) {
// 				ans.push_back(changed[i]);
// 			}
// 			return ans;

// 		}
// 		// for (auto& i : mp) {
// 		// 	cout << i.first << " " << i.second << endl;
// 		// }


// 		for (auto& i : mp) {
// 			if (s.find(i.first) != s.end() and s.find(i.second) != s.end()) {
// 				ans.push_back(i.first);
// 				s.erase(i.first);
// 				s.erase(i.second);
// 				mp.erase(i.second);
// 			}
// 			else {
// 				return {};
// 			}
// 		}
// 		return ans;

// 	}
// };



class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) {
		multiset<int>s;
		for (auto& i : changed) {
			s.insert(i);
		}
		s.erase(0);
		for (auto& i : s) {
			cout << "here" << endl;
			cout << i << " ";
		}
		return {};
	}
};
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);



	Solution obj;
	vector<int>changed = {1, 3, 4, 2, 6, 8};
	vector<int>changed2 = {0, 0, 0, 0};
	vector<int>changed3 = {2, 1};
	vector<int>changed4 = {6, 3, 0, 1};
	vector<int>changed5 = {0, 0, 0, 0, 0, 0, 1};
	vector<int>ans = obj.findOriginalArray(changed5);
	for (auto& i : ans) {
		cout << i << " ";
	}




	return 0;
}