#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
ll gcd(ll a,ll b)
{
	if(b==0)
        return a;

    else 
    	return gcd(b,a%b);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	int m =1;
	ld max = 0;
	ll a=1;
	ll b=1;
	for (ll i=1;i<=n-2;i++)
	{	if(m==0)
			break;
		else
		{	
			for (ll j=2 ; j<=n-1;j++)
			{
				if ((gcd(i,j) == 1) && (i+j)==n && (i<j))
				{
					ld x = i;
					ld y = j;
					ld ans = x/y;
					if(ans>max)
					{
						max=ans;
						a=i;
						b=j;
					}
				}
				else
					continue;
			}
		}
	}
	cout<<a<<" "<<b<<endl;	
	return 0;
}