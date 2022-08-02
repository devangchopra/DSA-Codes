//Bipartite Graph
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>graph[],int node,int *visited,int parent,int color)
{
	//Node
	visited[node]=color;

	for(auto nbr:graph[node])
	{
		if(visited[nbr]==0)
		{
			int subprob = dfs(graph,nbr,visited,node,3-color);

			if(subprob==false)
				return false;
		}
		else if(nbr!=parent and color==visited[nbr])
			return false;
	}

	return true;
}

bool is_bipartite(vector<int> graph[],int n)
{
	int visited[n]={0};
	//Color store
	//0 -> not Visited
	//1 -> visited + color 1
	//2 -> visited + color 2
	int color = 1;
	bool ans = dfs(graph,0,visited,-1,color);

	//Printing the colors
	for(int i=0;i<n;i++)
		cout<<i<<"Color"<<"	 "<<visited[i]<<endl;

	return ans;	

}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> graph[n];
	while(m--)
	{
		int i,j;
		cin>>i>>j;
		graph[i].push_back(j);
		graph[j].push_back(i);
	}

	if(is_bipartite(graph,n))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}