#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll 					long long int
#define ld 					long double
#define mod 				1e9+7
#define ps(x,y)   			fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>> 

#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>




int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;		

		ll sum=0;

		ll arr[2*n];

		for(ll i=0;i<2*n;i++)
		{
			cin>>arr[i];
		}

		ll e = 0;
		ll o = 0;



		for(ll i=0;i<2*n;i++)
		{
			if(arr[i]%2==0)
			{
				e++;
			}
			else{
				o++;
			}
		}

		if(e==o and o==n)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;

}