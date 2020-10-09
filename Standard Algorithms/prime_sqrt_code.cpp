#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime(ll n)
{
	if (n==1)
		return false;
	else
	{
		for(ll i =2;i*i<=n;i++)
		{
			if(n%i==0)
				return false;
		}
		return true;
	}
}
int main()
{
	ll n;
	cin>>n;
	cout<<isprime(n);
}