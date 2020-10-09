#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll isprime(ll n)
{
	ll sum =0;
	if(n==1)
		return ;
	else
	{
		for (ll i =2 ;i*i<=n;++i)
		{
			if(i%n==0)
				return ;
			else
				sum = sum +i;

		}
		
	}
	return sum;
}

int main()
{
	ll n;
	cin>>n;
	while(n--)
	{
		ll num;
		cin>>num;
		cout<<isprime(num)<<endl;
	}
}