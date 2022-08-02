#include<bits/stdc++.h>
using namespace std;

#define ll 	long long int


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{	
		ll n;
		cin>>n;

		vector<ll>arr;

		arr.push_back(n);

		for(int i=1;i<=n-1;i++)
		{
			arr.push_back(i);
		}

		for(auto i:arr)
		{
			cout<<i<<" ";
		}
		cout<<endl;


	}
	return 0;
}