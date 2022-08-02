#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
	int V;
	list<int>* l;

public:
	Graph(int v)
	{
		this->V=v;
		l = new list<int>[v];
	}

	void addEdge(int i,int j)
	{
		l[i].push_back(j);
	}

	bool dfs(int node,vector<bool> &visited, vector<bool> &stack)
	{
		visited[node]=true;
		stack[node]=true;

		//Check for backEdge
		for(int nbr:l[node])
		{
			if(stack[nbr]==true)
				return true;

			else if(visited[nbr]==false)
			{
				//Checking if nbr recursively brings a back edge
				bool nbrFoundACycle = dfs(nbr,visited,stack);
				if(nbrFoundACycle)
					return true;
			}
		}

		//Going Back
		stack[node]=false;
		return false;

	}

	bool contains_cycle()
	{
		vector<bool> visited(V,0);
		vector<bool> stack(V,0);

		//Different Componenets can be present
		for(int i=0;i<V;i++)
		{

			if(dfs(i,visited,stack))
			{
				return true;
			}
		}

		return false;
	}
};

int main()
{
	Graph g(6);
	g.addEdge(0,5);
	g.addEdge(0,4);
	g.addEdge(5,4);
	g.addEdge(3,0);
	//g.addEdge(2,3);
	g.addEdge(0,1);
	g.addEdge(1,2);

	cout<<g.contains_cycle();
}