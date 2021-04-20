#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string x;
	cin>>x;

	if(x[0]=='a' or x[0]=='c' or x[0]=='e' or x[0]=='g')
	{
		if (x[1]%2!=0)
		{
			cout<<true;
		}
		else
		{
			cout<<false;
		}
	}
	else
	{
		if(x[1]%2!=0)
		{
			cout<<false;
		}
		else
		{
			cout<<true;
		}
	}
}