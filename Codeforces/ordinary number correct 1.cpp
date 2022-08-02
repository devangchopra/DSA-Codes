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
		ll n;
		cin>>n;

		ll ans=0;
		for(ll i=1;i<9;i++)
		{
			for(j=i;j<=n;)
			{
				ans++;
				j=(j*10)+i;
			}
		}
		cout<<ans<<endl;
	}

}