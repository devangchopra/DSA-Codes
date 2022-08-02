#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll e;
	cin>>e;
	ll arr[e];
	for (ll i=0; i<e; i++)
	{
		cin>>arr[i];
	}
	reverse(arr+1, arr+e);
	for (ll i=0; i<e; i++)
	{
		cout<<arr[i];
	}
}