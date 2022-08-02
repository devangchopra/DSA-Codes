#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int>* l;

public:
	Graph(int v)
	{
		V=v;
		l=new list<int>[V];
	}

	void addEdge(int i , int  j , bool undir = true)
	{
		l[i].push_back(j);
		if(undir)
		{
			l[j].push_back(i);
		}
	}

	void bfs(int source)
	{
		bool* visited = new bool[V]{0};
		queue<int>q;
		q.push(source);
		visited[source]=true;

		while(q.empty()==false)
		{
			int f = q.front();
			cout<<f<<" ";
			q.pop();

			for(auto nbr:l[f])
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					visited[nbr]=true;
				}
			} 
		}
	}

	void dfs_helper(int source , bool* visited)
	{
		visited[source]=true;
		cout<<source<<" ";
		for(auto nbr:l[source])
		{
			if(!visited[nbr])
			{
				dfs_helper(nbr,visited);
			}
		}
	}

	void dfs(int source)
	{
		bool* visited = new bool[V]{0};
		dfs_helper(source,visited);
	}


	void dfsStack(int source)
	{
		bool* visited = new bool[V]{0};
		stack<int>s;
		s.push(source);

		while(s.empty()==false)
		{
			int t = s.top();
			
			s.pop();

			//Stack -> In place of recursion
			//so it may hold value twice
			//therefore print if not visited

			if(!visited[t])
			{
				cout<<t<<" ";
				visited[t]=true;
			}

			for(auto nbr:l[t])
			{
				if(!visited[nbr])
				{
					s.push(nbr);
				}
			}
		}
		
	}
	
};

int main()
{


	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);

	cout<<"BFS 	"<<endl;
	g.bfs(0);

	cout<<endl<<"DFS 	"<<endl;
	g.dfs(0);

	cout<<endl<<"DFS STACK 	"<<endl;
	g.dfsStack(0);
}