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



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{	
		string s;
		cin>>s;

		ll n = s.size();

		string left;
		string right;

		ll index = s.find("a");

		cout<<"INDEx"<<" "<<index<<endl;		

		if(index ==-1)
		{
			cout<<"NO"<<endl;
			break;
		}

		if(index>n)
		{
			index--;
		}
	
		for(ll i=0;i<index;i++)
		{
			left.push_back(s[i]);
		}

		for(ll i=index;i<s.size();i++)
		{
			right.push_back(s[i]);
		}

		cout<<endl<<left<<endl<<right<<endl;

		bool x = true;

		for(ll i=0;i<left.size()-1;i++)
		{
			if(!(left[i]<left[i+1]))
			{
				x=false;
				break;
			}
		}

		if(x==false)
		{
			cout<<"NO"<<endl;
			break;
		}

		for(ll i=0;i<right.size();i++)
		{
			if(!(right[i]<right[i+1]))
			{
				x=false;
				break;
			}
		}

		if(x)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}


}
/*

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{	
		string s;
		cin>>s;

		ll n = s.size();

		sort(s.begin(),s.end());

		bool x = true;

		for(int i=0;i<n;i++)
		{
			if(!(s[i]-'a'==i))
			{
				x = false; 
			}
		}

		if(x)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

*/

/*
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s = "ihfcbadeg";
	int n = s.size();

	bool x = true;

	sort(s.begin(),s.end());

	cout<<endl<<s<<" ";
	cout<<endl<<n<<" ";
	cout<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<s[i]-'a'<<endl;
		if(!(s[i]-'a'==i))
		{			
			x = false; 
		}
	}

	if(x)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

}
*/