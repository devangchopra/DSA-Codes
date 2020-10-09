#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	while(n--)
	{
		ll a ,b;
		cin>>a>>b;
		ll ans=0;
		while(a--)
		{
		    ll d;
		    cin>>d;
		    ans=ans+d;
		}
		long double m;
		long double B=b;
		m=ans/B;
		ll temp=m;
		cout<<temp+1<<endl;
		
	}
	return 0;
}