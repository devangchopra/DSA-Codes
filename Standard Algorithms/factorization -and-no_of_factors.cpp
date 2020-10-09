#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll number_of_factors(ll n)
{
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
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}
int main()
{
	ll a;
	cin>>a;
	number_of_factors(a);
	return 0;

}