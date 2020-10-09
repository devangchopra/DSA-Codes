#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
{
	if(a==0)
		return b;
	else if(b==0)
		return a;
	else if(a==b)
		return a;
	else if(a>b)
		return gcd(a-b,b);
	else
		return gcd(b,b-a);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	while(n--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}