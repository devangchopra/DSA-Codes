#include <iostream>
#include <list>
#include <queue>
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

	void addEdge(int i,int j,bool undir=true)
	{
		l[i].push_back(j);
		if(undir)
		{
			l[j].push_back(i);
		}
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

		//Visited Array
		bool* visited = new bool[V]{0};
		q.push(source);
		visited[source]=true;

		while(!q.empty())
		{
			//Work -> Every Node
			int f = q.front();
			cout<<f<<" ";
			q.pop();

			//We have to push the neighbours now
			//Neighours -> Adjacency List
			for(auto nbr:l[f])
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					visited[nbr]=true;
					//not processed but that is in the queue
				}
			}
		}
	}

};


int main()
{

	Graph b(7);
	b.addEdge(0,1);
	b.addEdge(1,2);
	b.addEdge(2,3);
	b.addEdge(3,5);
	b.addEdge(5,6);
	b.addEdge(4,5);
	b.addEdge(0,4);
	b.addEdge(3,4);
	b.bfs(1);
}