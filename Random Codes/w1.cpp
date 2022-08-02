#include<bits/stdc++.h>
using namespace std;
#define ll 	long long int
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string  str;
	cin>>str;

	map<int,int>m;

	//For 'U'
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='U')
		{
			m[i]=str.length()-i-1;
		}
	}

	for(int i=str.length()-1;i>=0;i--)
	{
		if(str[i]=='D')
		{
			m[i]=i;
		}
	}

	for(auto i:m)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}

	int ans=0;




	
	return 0;
}