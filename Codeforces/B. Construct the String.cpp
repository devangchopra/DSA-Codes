#include <bits/stdc++.h>
using namespace std;
string temp = "abcdefghijklmnopqrstuvwxyz";
void fun() {
	int n, a, b;
	cin >> n >> a >> b;

	//n-Length
	//a-substring
	//b-Distint

	string ans = "";
	int index = 0;
	while (ans.size()< n) 
	{
		if (index == b ) {index = 0;}
		ans.push_back(temp[index]);
		index++;
	}
	cout<<ans<<endl;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		fun();
	}
	return 0;
}