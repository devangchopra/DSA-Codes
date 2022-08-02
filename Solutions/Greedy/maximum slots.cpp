#include <bits/stdc++.h>
using namespace std;

int maximumstocks(vector<pair<int,int>>& v,int k)
{
	int ans=0;
	sort(v.begin(),v.end());

	for(int i=0;i<v.size();i++)
	{
		int price=v[i].first;
		int stock=v[i].second;

		if(price*stock<=k)
		{
			ans+=stock;
			k-=(price*stock);
		}
		else
		{
			ans+=(k/price);
			k-=price*(k/price);
		}
	}

	return ans;

}

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int k;
	cin>>k;

	vector<pair<int,int>>v;
	for(int i=0;i<n;i++)
	{
		pair<int,int>p;
		p.first=arr[i];
		p.second=i+1;
		v.push_back(p);
	}
	cout<<maximumstocks(v,k)<<'\n';
}