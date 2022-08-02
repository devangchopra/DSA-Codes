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
		//find first 2k+1 terms
		vector<ll>v;
		for(ll i=1;i<=2*k+1;i++)
		{
			v.push_back(k+(i*i));
		}

		//gcd
		ll ans=0;
		for(ll i=0;i<v.size()-1;i++)
		{
			ans+=gcd(v[i],v[i+1]);
		}
		cout<<ans<<endl;

	}
}