#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s = "";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		s.push_back(i + 48);
	}
	cout << s << endl;
	int c = s[s.size() - 1] - 48;
	for (int i = 1; i < s.size() - 1; i++)
	{
		cout << s[i] << c << endl;
	}
	cout << c << endl;
	return 0;
}


