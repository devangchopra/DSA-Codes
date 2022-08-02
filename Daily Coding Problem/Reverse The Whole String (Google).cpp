/*
This question is asked by Google. Given a string, reverse all of its characters and return the resulting string.

Ex: Given the following strings...

“Cat”, return “taC”
“The Daily Byte”, return "etyB yliaD ehT”
“civic”, return “civic”
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin,s);

	stack<char>temp;

	for(int i=0;i<s.size();i++)
	{
		temp.push(s[i]);
	}
	string ans="";

	while(temp.empty()==false)
	{
		ans+=temp.top();
		temp.pop();
	}

	cout<<ans<<endl;
	return 0;
}