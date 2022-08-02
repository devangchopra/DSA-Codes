#include<bits/stdc++.h>
using namespace std;

#define ll 		long long int

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		ll arr[n];

		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		ll count=0;

		for(ll i=0;i<n;i++)
		{
			if(arr[i]<i+1)
			{
				continue;
			}
			else
			{
				ll ans=arr[i]-(i+1);

				cout<<ans<<endl;

				for(ll j=ans-1;j<n;++j)
				{
					if(arr[i]*arr[j]==i+j)
					{
						count++;
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}