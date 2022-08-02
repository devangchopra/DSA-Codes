#include<bits/stdc++.h>
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

  void addEdge(int i,int j,bool undir=true)
  {
    l[i].push_back(j);
    if(undir)
    {
      l[j].push_back(i);
    }
  }


  int min_path(int source,int destinaiton)
  {
    queue<int>q;
    q.push(source);

    bool* visited = new bool[V]{0};
    int* distance = new int[V];

    for(int i=0;i<V;i++)
    {
      distance[i]=0;
    }

    distance[source]=0;
    visited[source]=true;

    while(q.empty()==false)
    {
      int f = q.front();
      q.pop();

      for(auto nbr:l[f])
      {
        if(!(visited[nbr]))
        {
          q.push(nbr);
          visited[nbr]=true;
          distance[nbr]=distance[f]+1;
        }
      }
    }

    if(distance[destinaiton]<=0)
    {
      return -1;
    }

    return distance[destinaiton]+1;
  }

};


int messageRoute(int n, vector<vector<int>>edges)
{
    //Build the graph
    Graph g (n+1);

    for(int i=0;i<n;i++)
    {
      g.addEdge(edges[i][0],edges[i][1]);
    }

    return  g.min_path(1,n);

}