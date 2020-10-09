#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int t;
	cin>>t;
	long long int T =t+1;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int x;
		cin>>x;
		vector<long long int> v;
		vector<long long int> f;
		for (int i=0 ; i<n ;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}		
		while(v.empty()!=true)
		{
			long long int x =0;
			if (v[0]<=x)
			{
				v.erase(v.begin());
				f.push_back(x+1);
				x++;
			}
			else
			{
				v.push_back(v[0]-x);
				v.erase(v.begin());
				x++;
			}
		}
		for (int i=0;i<n;i++)
		{
			cout<<f[i]<<" ";
		}

	}
}