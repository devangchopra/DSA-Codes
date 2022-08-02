#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long long double
#define md 1e9+7

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll T;
	cin>>T;
	while(T--)
	{
		ll n,x,t;
		cin>>n>>x>>t;

		ll temp=n;
		ll left=0;

		ll count=0;

		ll max_value=x*(n-1);

		//cout<<max_value<<endl;

		while(temp--)
		{

			ll right=left+t;
			for(ll i=left+1;i<=right;i++)
			{
				if(i%x==0 and i<=max_value)
				{
					count++;
				}
			}
			left=left+x;
			
		}
		cout<<count<<endl;		
	}
}