#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string ans;
	for (auto c : s)
	{
		if (c != '+')
			ans.push_back(c);
	}
	int n = ans.size();
	sort(ans.begin(),ans.end());
	s = ans;
	ans = "";
	for (auto i : s)
	{
		ans.push_back(i);
		ans.push_back('+');
	}
	ans.pop_back();
	cout << ans << endl;
	return 0;
}
