#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll ans=0;
		vector<ll> v(n+1,1);
		for(ll i=2;i<=n;i++)
		{
			ll a=m%i;
			ans=ans+v[a];
			for(ll j=a;j<=n;j=j+i)
			{
				v[j]++;
				//if a divides then multiple will also divide
			}
		}
		cout<<ans<<endl;
	}
}