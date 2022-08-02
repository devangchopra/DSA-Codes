#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
	if(b==0)
        return a;

    else return gcd(b,a%b);

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll k;
		cin>>k;

		ll ans=0;
		for(ll i=1;i<=2*k;i++)
		{
			ll a=k+i*i;
			ll b=k+((i+1)*(i+1));
			ans=ans+gcd(a,b);
		}
		cout<<ans<<endl;
	}
}