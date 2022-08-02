#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x,k;
		cin>>n>>x>>k;
		
		bool flag=false;
		for(ll i=0;i<=n+1;i=i+k)
		{
			//traversing linearly
			if(i==x)
			{
				flag=true;
				break;
			}		

		}
		//-----------------
		if(flag==false)
		{
			for(ll i=n+1;i>=0;i=i-k)
			{
				//traversing backward
				if(i==x)
				{
					flag=true;
					break;
				}
			}
		}
		

		if(flag==true)
		{
			cout<<"YES"<<endl;	
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}