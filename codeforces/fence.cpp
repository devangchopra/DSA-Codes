#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,h;
	cin>>n>>h;
	ll arr[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	ll count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=h)
			count++;
		else
			count+=2;
	}
	cout<<count<<endl;
}