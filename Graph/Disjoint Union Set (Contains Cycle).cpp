#include <iostream>
#include <list>
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
	void addEdge(int x,int y)
	{
		l.push_back(make_pair(x,y));
	}

	int findset(int i,int parent[])
	{
		//base case
		if(parent[i]==-1)
			return i;

		return findset(parent[i],parent);
	}

	void union_set(int x,int y,int parent[])
	{
		int s1=findset(x,parent);
		int s2=findset(y,parent);

		if(s1!=s2)
		{
			parent[s2]=s1;
		}
	}

	bool contains_cycle()
	{
		int* parent = new int[V+1];

		for(int i=0;i<V;i++)
		{
			parent[i]=-1;
		}

		for(auto edge:l)
		{
			int i=edge.first;
			int j=edge.second;

			int s1=findset(i,parent);
			int s2=findset(j,parent);

			if(s1!=s2)
			{
				union_set(s1,s2,parent);
				//dobara need ni hogi find krne ki
				//recusrsion base case se return krdega
			}
			else
			{
				cout<<"contains_cycle"<<endl;
				return true;
			}
		}
		return false;
	}
};

int main()
{
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	//g.addEdge(3,0);

	cout<<g.contains_cycle()<<endl;
}