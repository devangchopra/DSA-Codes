#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll r1,n,r2,x;
	cin>>r1>>n>>r2>>x;

	ll hours = ceil(x/60.0);

	ll ans=0;

	ans = ans + (r1*n);
	n = hours-n;

	ans = ans + (r2*n);

	cout<<ans<<endl;


}
