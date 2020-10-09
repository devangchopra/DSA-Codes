#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		map<ll,ll> mp;
		for(ll i=2;i*i<=n;i++)
		{
			while(n%i==0)
			{
				mp[i]++;
				n=n/i;
			}
			if(n>1)
			{
				mp[n]++;
				n=1;
			}
		}
		for(auto i:mp)
		{
			if(i.second%2!=0)
			{
				cout<<i.first<<" ";
			}
		}
	}
	return 0;
}