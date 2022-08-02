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
#define endl        		"\n"
//Use endl wisely buffer flush 

#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

void fun(ll n)
{
	ll qt = n/3;
	ll rm = n%3;

	if(rm==0)
	{
		cout<<qt<<" "<<qt<<endl;
		return;
	}

	else if(rm%2==0)
	{
		ll temp = rm;
		temp = temp/2;
		temp=temp+qt;

		cout<<qt<<" "<<temp<<endl;
		return;
	}
	else
	{
		ll temp = qt;
		qt+=rm;
		cout<<qt<<" "<<temp<<endl;
		return;
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		fun(n);
	}
	return 0;
}