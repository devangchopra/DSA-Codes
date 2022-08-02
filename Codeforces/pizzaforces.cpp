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


//GCD
ll gcd(ll a,ll b)
{
	if(b==0)
        return a;

    else return gcd(b,a%b);

}


void fun(ll n)
{
	if(n<=6){
		cout<<15<<endl;
		return;
	}

	if(n%2==0)
	{
		cout<<(n/2)*5l<<endl;
		return;
	}
	else
	{
		n++;
		cout<<(n/2)*5l<<endl;
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