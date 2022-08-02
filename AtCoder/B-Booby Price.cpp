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



void fun()
{
	int a;
	cin>>a;
	int* arr = new int[a];

	for(int i=0;i<a;i++) cin>>arr[i];

	int maximum=INT_MIN;
	int second_maximum=INT_MIN;

	int index_of_maximum=0;
	int index_of_second_maximum=0;

	for(int i=0;i<a;i++)
	{
		if(arr[i]>maximum)
		{
			second_maximum=maximum;
			index_of_second_maximum=index_of_maximum;
			maximum=arr[i];
			index_of_maximum=i;
		}
		else if(arr[i]>second_maximum and second_maximum<maximum)
		{
			second_maximum=arr[i];
			index_of_second_maximum=i;
		}
	}

	cout<<index_of_second_maximum+1<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fun();
	return 0;
}