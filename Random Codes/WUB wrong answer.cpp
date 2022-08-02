#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<char>v;

	if(s.size()<3)
	{
		cout<<s;
	}
	else
	{
		
		for(int i=0;i<s.size()-3;i++)
		{
			if(s[i]=='W' and s[i+1]=='U' and s[i+2]=='B')
			{
				continue;
			}
			else
			{
				v.push_back(s[i]);
			}
		}
	}
	for(auto i:v)
	{
		cout<<i;
	}
}