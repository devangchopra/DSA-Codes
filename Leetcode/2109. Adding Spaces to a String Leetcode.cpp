#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string addSpaces(string s, vector<int>& spaces) {
		string ans;
		int counter = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			if (counter < spaces.size() and spaces[counter] == i) {
				ans.push_back(' ');
				counter++;
				i--;
			}
			else {
				ans.push_back(s[i]);
			}
		}
		return ans;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution obj;
	string s = "icodeinpython";
	std::vector<int> spaces = {1, 5, 7, 9};
	string r = obj.addSpaces(s, spaces);
	cout << r << endl;
	return 0;
}
