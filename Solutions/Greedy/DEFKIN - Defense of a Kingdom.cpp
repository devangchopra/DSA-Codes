#include<bits/stdc++.h>
using namespace std;
#define ll 					long long int

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll w,h,n;
		cin>>w>>h>>n;

		unordered_set<ll>x;
		unordered_set<ll>y;

	

		while(n)
		{
			ll p1,p2;
			cin>>p1,p2;

			x.insert(p1);
			y.insert(p2);

			if(p1+1<=w)
			{
				x.insert(p1+1);
			}
			if(p2+1<=h)
			{
				y.insert(p2+1);
			}
			n--;

		}

		ll area=0;

		for(ll i=1;i<=w;i++)
		{
			ll x_length=0;
			if(!(x.count(i)>0))
			{
				x_length++;
			}
			else
			{
				ll y_max=0;
				for(ll j=1;j<=h;j++)
				{
					ll temp=0;
					if(!(y.count(j)>0))
					{
						temp++;
					}
					else
					{
						y_max=max(y_max,temp);
						temp=0;
					}
				}
				ll temp_area=x_length*y_max;
				area=max(temp_area,area);
			}
			
		}
		cout<<area<<endl;

	}
	return 0;
}