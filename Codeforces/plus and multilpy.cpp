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
		ll n ,a , b;
		cin>>n>>a>>b;

		while(n>1)
		{
			if(n%a==0 and a!=1)
			{
				n=n/a;

				//cout<<"Now Dividing"<<" "<<n<<endl;
			}
			else
			{
				//optimization
				ld ps=(n-b)/a;
				ll pss=(n-b)/a;
				if(ps-pss!=0)
				{
					ll temp;
					temp=n/b;
					temp--;
					cout<<temp<<endl;
					if(temp>1)
					{
						n=n-(temp*b);
					}
				}				
				else
				{
					//cout<<n<<" "<<"Now i m doing this"<<endl;
					n=n-b;
				}
				
				//cout<<"Now Subtracting"<<" "<<n<<endl;
			}
		}
		//cout<<"Final n"<<" "<<n<<endl;
		if(n==1)
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