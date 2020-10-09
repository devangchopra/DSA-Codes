#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll ntc;
	cin>>ntc;
	while(ntc--)
	{
		ll a;
		cin>>a;
		ll arr[a];
		for(ll i=0;i<a;i++)
		{
			arr[i]=i+1;
		}
		ll count =1;
		ll* fptr=&arr[0];

		ll* bptr=&arr[a-2];
		/*cout<<*fptr<<endl;
		cout<<*bptr<<endl;*/
		for (ll i=0;i<a;i++)
		{
			if(*fptr<*bptr)
			{
				if(*fptr+*bptr==arr[a-1])
				{
					count++;
					fptr++;
					bptr--;
					/*cout<<*fptr<<endl;
					cout<<*bptr<<endl;*/
				}
			}

			
		}
		cout<<count<<endl;
	}
	return 0;
}