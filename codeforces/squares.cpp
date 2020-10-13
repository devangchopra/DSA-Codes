#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll ntc;
	cin>>ntc;
	while(ntc--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n, greater<int>());
		ll inner=arr[0];
		ll outer =0;
		for(int i=0;i<n;i++)
		{
			inner=min(inner,arr[i]);
			outer=max(outer,inner);
		}
		cout<<outer<<endl;

	}
	
}