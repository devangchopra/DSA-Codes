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

void fun(string s, int n)
{
	if(n==1)
	{
		cout<<0<<endl;
		return;
	}
	unordered_map<char,int>m;

	for(auto c : s)
	{
		m[c]++;
	}

	if(m.size()==1)
	{
		cout<<1<<endl;
		return;
	}

	int sum = 0;

	for(auto p:m)
	{
		if(p.second>2)
		{
			sum=sum+2;
		}
		else
		{
			sum=sum+p.second;
		}
	}

	sum = sum/2;

	cout<<sum<<endl;
	return;
}




int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.size();
		fun(s,n);

	}
	return 0;
}