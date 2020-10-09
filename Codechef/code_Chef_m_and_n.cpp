#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll x ,y;
		cin>>x>>y;
		std::vector<bool> isthisprime(y+1,true);
		isthisprime[0]=false;
		isthisprime[1]=false;
		for(int i=2;i<=y;i++)
		{
			if(isthisprime[i]==true)
			{
				for(int j=i*2;j<=y;j+=i)
				{
					isthisprime[j]=false;
				}
			}
		}
		ll sum=0;
		for(ll i=x;i<=y;i++)
		{
			if(isthisprime[i]==true)
				sum=sum+i;

		}
		cout<<sum<<endl;
	}
		
}