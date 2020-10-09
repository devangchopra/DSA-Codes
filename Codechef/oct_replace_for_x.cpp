#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,x,p,k;
		cin>>n>>x>>p>>k;
		ll arr[n];
		for(ll i=0;i<n;i++)
		{	
			cin>>arr[i];
		}
		sort(arr,arr+n);
		ll count =0;
		for(ll i=0;i<n;i++)
		{
			if(arr[p-1]==x)
			{
				count++;
				break;
			}
			else
			{
				arr[k-1]=0;
				count++;
				sort(arr,arr+n);
			}
		}
		if(count==0)
			cout<<-1<<endl;
		else
			cout<<count<<endl;

	}
}