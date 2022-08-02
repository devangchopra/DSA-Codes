#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;

	while(t--)
	{
		ll n,k;

		cin>>n;
		cin>>k;

		string s1;
		cin>>s1;
        
		if(k==1)
		{
		    
			int x=0;
			for(ll i=0;i<s1.length();i++)
			{
				if(s1[i]=='*')
				{
					x=1;
					break;
				}
			}
			
			if(x==1)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else
		{

			ll count=1;
			vector<ll>v;
			for(ll i=0;i<s1.length();i++)
			{
				if(s1[i]=='*' and s1[i+1]=='*')
				{
					count++;
				}
				else
				{
					v.push_back(count);
					count=1;
				}
			}
			// till now not handling the 1 star case
			ll max = *max_element(v.begin(), v.end());
			if(max>=k)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
}


