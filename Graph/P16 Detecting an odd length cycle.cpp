#include<bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<vector<int>>graph,int node,int* visited,int parent,int color)
{
	visited[node]=color;

	for(auto nbr:graph[node])
	{
		if(visited[nbr]==0)
		{
			bool subprob = dfs_helper(graph,nbr,visited,node,3-color);
			if(subprob==false)
			{
				return true;
			}
		}

		else if(nbr!=parent and color==visited[nbr])
		{
			return false;
		}
	}

	return true;
}

bool is_bipartite(vector<vector<int>> graph,int n)
{
	int visited[n]={0};
	int color = 1;

	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			if(dfs_helper(graph,i,visited,-1,color)==false)
				return true;
		}
	}

	return false;

}

bool solve(vector<vector<int>> graph)
{
	int n = graph.size();

	return is_bipartite(graph,n);

	
}