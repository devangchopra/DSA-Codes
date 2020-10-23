#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll k=1;k<=n;k++)
	{
		
		ll nsquare=k*k;
		ll total= nsquare*(nsquare-1)/2;
		ll rect= 4*(k-1)*(k-2);
		cout<<total-rect<<endl;
	}

	return 0;
}