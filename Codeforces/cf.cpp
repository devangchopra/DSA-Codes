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


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll* arr=new ll[n];
		ll* brr=new ll[n];

		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>brr[i];
		}

		//a->b;

		ll operations = 0;

		vector<pair<ll,ll>>v;
		pair<ll,ll>p;
		while(operations<=100)
		{
			ll i=0;
			ll j=n-1;

			p={-1,-1};

			if(arr[i]!=brr[i] and arr[i]-1!=0 and arr[i]<=brr[i])
			{
				p.first=i;
				arr[i]--;
			}
			else if(arr[i]!=brr[i] and arr[i]-1==0 and (!(arr[i]<=brr[i])))
			{
				i++;
			}
			else if(arr[j]!=brr[j] and arr[j]<=brr[j])
			{
				p.second=j;
				arr[j]--;
			}
			else if(!(arr[j]!=brr[j] and arr[j]<=brr[j]))
			{
				j--;
			}

			else if(arr[i]==brr[i] and arr[j]==brr[j])
			{
				i++;
				j--;
			}

			if(p.first!=-1 and p.first!=-1)
			{
				v.push_back(p);
				operations++;
			}

		}

		cout<<operations<<endl;
		for(auto p:v)
		{
			cout<<p.first<<" "<<p.second<<endl;
		}

	}
	return 0;
}