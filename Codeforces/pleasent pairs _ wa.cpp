#include<bits/stdc++.h>
using namespace std;

#define ll 		long long int

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

		for(ll i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			arr.push_back(x);
		}

		unordered_map<ll,ll>m;

		ll f=1;
		for(auto i:arr)
		{
			pair<ll,ll>p;
			p={f,i};
			m.insert(p);

			f++;
		}

		ll count=0;

		for(ll i=0;i<n;i++)
		{
			if(arr[i]<i+1)
			{
				// do nothing
			}
			else
			{
				ll ans_key=arr[i]-(i+1);

				while(m.count(ans_key)>0)
				{
					//cout<<"ans Key"<<" "<<ans_key<<endl;
					//cout<<"Product "<< m[ans_key]*arr[i]<<" "<<"Key"<<" "<<ans_key+i+1<<endl;
					if(m[ans_key]*arr[i]==ans_key+i+1)
					{

						count++;
					}
					ans_key++;
				}
			}

		}

		cout<<count<<endl;
	}
	return 0;
}