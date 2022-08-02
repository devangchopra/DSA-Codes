#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <pair>
#define endl "\n"
using namespace std;

class Graph
{
	int V;
	//Number Of Vertices
	list<int>* l;

	public:

	Graph(int v)
	{
		V=v;
		l=new list<int>[V];
	}

	void addEdge(int i,int j)
	{
		l[i].push_back(j);
	}

	void printAdjList()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<" "<<"->"<<" ";
			for(auto node:l[i])
			{
				cout<<node<<" ";
			}
			cout<<endl;
		}
	}

	void bfs(int source)
	{
		queue<int>q;
		q.push(source);

		bool* visited;
		visited = new bool[V];

		for(int i=0;i<V;i++)
		{
			visited[V]=0;
		}
		visited[source]=true;

		//Neighbours
		while(q.empty()==false)
		{
			int f = q.front();
			cout<<f<<" ";
			q.pop();

			for(auto nbrs:l[f])
			{
				if(visited[nbrs]!=1)
				{
					q.push(nbrs);
					visited[nbrs]=true;
				}
			}
		}
	}

	int shortest_path(int source,int destination)
	{
		queue<int>q;
		q.push(source);

		bool* visited;
		visited = new bool[V];

		int* distance = new int [V]{0};
		

		for(int i=0;i<V;i++)
		{
			visited[V]=0;
		}
		visited[source]=true;

		parent[source]=source;
		distance[source]=0;

		//Neighbours
		while(q.empty()==false)
		{
			int f = q.front();
			q.pop();

			for(auto nbrs:l[f])
			{
				if(visited[nbrs]!=1)
				{
					q.push(nbrs);
					visited[nbrs]=true;
					distance[nbrs]=distance[f]+1;
				}
			}
		}

		return distance[destination];

	}

};

int min_dice_throws(int n,vector<pair<int,int>> snakes, vector<pair<int,int>> ladders){

	vector<int> delta(n+1,0);

	for(auto sp:snakes)
	{
		int s = sp.first;
		int e = sp.second;

		delta[s] = e-s;
	}

	for(auto lp:ladders)
	{
		int s = lp.first;
		int e = lp.second;

		delta[s] = e-s;
	}

	//Build the graph

	Graph g(n+1);
	for(int u = 1; u<n ;u++)
	{
		for(int dice=1;dice<=6;dice++)
		{
			int v = u + dice;
			v = v+delta[v];

			if(v<=n)
			{
				g.addEdge(u,v);
			}
		}
	}

	return g.shortest_path(1,n);    
}