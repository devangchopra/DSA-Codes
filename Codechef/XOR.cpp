#include<bits/stdc++.h>
using namespace std;
#define ll long long 
long long power(long long x, long long  int y, long long int p)
{
		long long res = 1;	 // Initialize result

		x = x % p; // Update x if it is more than or
						// equal to p

		if (x == 0) return 0; // In case x is divisible by p;

		while (y > 0)
		{
				// If y is odd, multiply x with result
			if (y & 1)
				res = (res*x) % p;

				// y must be even now
			y = y>>1; // y = y/2
			x = (x*x) % p;
		}
		return res;
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
		ll n;
		cin>>n;
		ll m=1000000007;
		long long ans=power(2,n-1,m);
		cout<<ans<<endl;
	}

}
