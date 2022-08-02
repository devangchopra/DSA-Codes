#include<bits/stdc++.h>
using namespace std;

#define ll 			long long int
#define ld 			long double
#define mod 		1e9+7

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

		ll sum=0;

		for(ll i=0;i<n;i++)
		{
			sum=sum+arr[i];
		}

		ld ans=sum/n;
		if(ans==1)
		{
			cout<<0<<endl;
		}
		else
		{
			ll count=0;
			while(ans!=1)
			{
				count++;
				n=n+1;
				ll x=abs(n-sum);
				sum=sum+x;		
				ans=sum/n;
			}
		}
	}

}