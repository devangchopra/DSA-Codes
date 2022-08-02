/*
#include <bits/stdc++.h>
using namespace std;

class graph
{
	//Considering undirected Graph

	int V;
	list<int>* l;

public:

	graph(int v)
	{
		this->V=v;
		l = new list<int> [V];
		//Array of lists
	}

	void addEdge(int i ,int j)
	{
		l[i].push_back(j);
		l[j].push_back(i);
	}

	void dfs_helper(int source,bool* visited)
	{
		visited[source]=true;
		//Print and go in depth
		cout<<source<<" ";
		for(auto nbr:l[source])
		{
			if(!visited[nbr])
			{
				visited[nbr]=true;
				dfs_helper(nbr,visited);
			}
		}
	}

	void dfs(int source)
	{
		bool* visited = new bool[V]{0};
		dfs_helper(source,visited);
	}

	

};
int main()
{
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	g.dfs(0);
	cout<<endl;
}



//Cycle Detection in Undirected Graph
#include <bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	list<int>* l;

public:
	graph(int v)
	{
		this->V=v;
		l = new list<int>[V];
	}
	void addEdge(int i,int j)
	{
		l[i].push_back(j);
		l[j].push_back(i);
	}

	bool dfs(int node,vector<bool> &visited,int parent)
	{
		visited[node]=true;

		for(auto nbr:l[node])
		{
			if(!visited[nbr])
			{
				//Now i have to check wheter the nbr's nbrs can contain the cycle or not

				bool nbrFoundACycle = dfs(nbr,visited,node);

				if(nbrFoundACycle)
					return true;
			}

			else if(nbr!=parent)
			{
				//We are checking for every nbr
				//that nbr!=parent
				return true;
			}
		}

		//If we come out of this
		//There is no cycle
		return false;

	}

	bool contains_cycle()
	{
		vector<bool>visited(V,false);
		return dfs(0,visited,-1);
		//Node , Visited , Parent

	}
};

int main()
{
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	cout<<g.contains_cycle()<<endl;

}



//Cycle Detection in directed Graph
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int> graph[],vector<bool>  visited,vector<bool> &stack)
{
	visited[node]=true;
	stack[node]=true;

	//We will be looking for backegde

	for(auto nbr:graph[node])
	{
		if(stack[nbr]==true)
		{
			//Node -> nbr is on same path
			//From which node is travelling
			return true;
			//Immediate Backedge
		}
		else if(visited[nbr]==false)
		{
			bool nbrFoundACycle=dfs(nbr,graph,visited,stack);
			if(nbrFoundACycle)
				return true;

			//As directed so no need of oscillate
		}
	}

	stack[node]=false; //Some one else can follow that path
	return false;
}

bool contains_cycle(vector<int> graph[],int n)
{
	vector<bool>visited(n,0);
	vector<bool>stack(n,0);

	//Graph can be disconnected
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			if(dfs(i,graph,visited,stack))
				return true;
		}
	}
	return false;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> graph[n];
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
	}

	cout<<contains_cycle(graph,n)<<endl;
}

*/

