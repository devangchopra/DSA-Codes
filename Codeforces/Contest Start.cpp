#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long long double
#define md 1e9+7

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll T;
	cin>>T;
	while(T--)
	{
		ll n,x,t;
		cin>>n>>x>>t;

		//0,x,2x,3x......n
		vector<ll>s;

		ll now=0;
		s.push_back(now);

		ll participant=1;
		while(participant<n)
		{
			now=now+x;
			s.push_back(now);
			participant++;
		}

		//for(auto i :s)
		//{
			//cout<<i<<" ";
		//}
		//cout<<endl;

		ll count =0 ;

		for(ll i=0;i<s.size();i++)
		{
			ll left=s[i]+1;
			ll right=s[i]+t;

			//cout<<"Left"<<" "<<left<<" "<<"Right"<<" "<<right<<endl;
			for(ll j=i+1;j<s.size();j++)
			{
				if(s[j]>=left and s[j]<=right)
				{
					//cout<<"Now j="<<" "<<s[j]<<" ";
					count++;
				}

			}
			//cout<<endl;
		}

		cout<<count<<endl;
	}
}