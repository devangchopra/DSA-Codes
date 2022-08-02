#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1="ABCD";
	string s2="CDBA";
	string temp=s1+s1;
	if(temp.find(s2)==string::npos)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}

}