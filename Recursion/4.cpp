#include<bits/stdc++.h>
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
		ll n;
		cin>>n;
		std::vector<ll> dp; //v
		dp.push_back(20);
		dp.push_back(36);
		dp.push_back(51);
		dp.push_back(60);

		if(n<=4)
		{
			cout<<dp[n-1]<<endl;
		}
		else
		{
			ll final=44*(n/4); //ans //doing it here
			ll multiple=n%4; //temp

			if(multiple==0)
			{
				//final=44*(n/4);
				final=final+6;
				final=final+10;
			}
			else
			{
				//final=44*(n/4);
				final=final+4*(4-multiple);
				final=final+dp[multiple-1];
			}
			cout<<final<<endl;
		}

	}