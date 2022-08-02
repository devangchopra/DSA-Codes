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

#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

void dfs(int node,vector<int> &ans, int* visited,set<int> l[],int parent)
{
	visited[node]=true;
	ans.push_back(node);

	//okay there are some nodes which were unvisited

	for(auto i:l[node])
	{
		if(visited[i]==false)
		{
			//Visit it
			dfs(i,ans,visited,l,node);
			
		}
	}
	if(parent!=0)
		ans.push_back(parent);

	//The loop will visit every node

	return;
}

void helper(vector<int> &ans, set<int> l[],int N)
{
	int* visited = new int[N+1]{0};	
	dfs(1,ans,visited,l,0);

	return;
}

void fun()
{
	int N;
	cin>>N;

	int temp=N-1;

	set<int> l[N+1];

	while(temp--)
	{
		int x,y;
		cin>>x>>y;

		l[x].insert(y);
		l[y].insert(x);
		//Sorted Adjacency List
	}

	vector<int>ans;

	helper(ans,l,N);
	for(auto i:ans)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fun();
	return 0;
}