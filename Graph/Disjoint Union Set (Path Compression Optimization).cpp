#include <bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	list<pair<int,int>>l;

public:
	graph(int V)
	{
		this->V=V;
	}
	void addEdge(int i,int j)
	{
		l.push_back(make_pair(i,j));
	}
	int find_set(int i,int parent[])
	{
		if(parent[i]==1)
			return i;

		return parent[i]=find_set(parent[i],parent);
		//Making the connections with super parent / leader
	}

	void union_set(int x,int y,int parent[])
	{
		int s1=find_set(x);
		int s2=find_set(y);

		if(s1!=s2)
		{
			parent[s2]=s1;
		}
	}


}