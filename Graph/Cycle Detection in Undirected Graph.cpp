//Cycle Detetction In Undirected Graph
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int>* l;

public:
	Graph(int v)
	{
		this->V=v;
		l = new list<int> [V];
	}

	void addEdge(int i,int j , bool udir = true)
	{
		l[i].push_back(j);
		if(udir)
		{
			l[j].push_back(i);
		}
	}

	bool dfs(int node , bool* visited, int parent)
	{
		//Mark node as visited
		visited[node] = true;
		for(auto nbr: l[node])
		{
			if(!visited[nbr])
			{
				bool nbrFoundACycle = dfs(nbr,visited,node);

				if(nbrFoundACycle)
				{
					return true;
				}
			}
			else if(nbr!=parent)
			{
				return true;
			}
		}

		return false;
	}

	bool contains_cycle()
	{
		//Assumption : Graph is single component
		//All vertices are connected to each other

		bool* visited = new bool [V]{0};

		return dfs(0,visited,-1);
		//0-> starting node , -1-> parent of 0
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	//g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(4,3);

	cout<<g.contains_cycle()<<endl;
}