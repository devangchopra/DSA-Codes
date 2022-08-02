#include<bits/stdc++.h>
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


bool canFinish(vector<vector<int>> edges,int numCourses) {
    
    Graph g(numCourses);

    for(int i=0;i<edges.size();i++)
    {
    	int x = edges[i][0];
    	int y = edges[i][1];

    	g.addEdge(x,y);
    }

    if(!g.contains_cycle())
    	return true;

    return false;
}

int main()
{
	cout<<canFinish({{1,0}},2);
}


//Check on leetcode 207
