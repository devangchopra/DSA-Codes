#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string st;
	cin >> st;
	stack<char>s;
	//Internally
	for (auto& i : st) {
		s.push(i);
	}
	while (s.empty() == false) {
		cout << s.top() << " ";
		s.pop();
	}



	return 0;
}