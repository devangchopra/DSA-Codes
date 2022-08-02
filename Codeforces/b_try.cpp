#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;

		ll arr[n];

		for (ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		ll sum = 0;

		for(ll i=0 ; i<n;i++)
		{
			sum=sum+arr[i];
		}

		ll ans = (sum%n);

		ll temp = n-ans;

		temp=temp * ans;

		cout<<temp<<endl;
	}

	return 0;
}