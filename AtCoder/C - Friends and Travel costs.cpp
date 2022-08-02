#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	map<ll,ll>m;
	while(n--)
	{
		ll a,b;
		cin>>a>>b;
		m[a]=m[a]+b;
	}
	ll ans=0;
	while(k)
	{
		ans++;
		k--;
		k=k+m[ans];
	}
	cout<<ans;
	return 0;	
}