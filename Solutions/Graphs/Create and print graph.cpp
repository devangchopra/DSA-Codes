
#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int V;
	list<int> *l;
public:
	Graph(int v)
	{
		V=v;
		l=new list<int>[V];
	}

	void addEdge(int x,int y,bool undir=true)
	{
		l[x].push_back(y);
		if(undir)
		{
			l[y].push_back(x);
		}
	}

	void printAdjLsit()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<"	";
			for(auto node:l[i])
			{
				cout<<node<<" ";
			}
			cout<<endl;
		}
	}
	
};

int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);


	g.printAdjLsit();

}


//This is applicable when we have vertex values : 0-> V-1 when we have V vertices

//Else

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class Node
{
public:
	int data;
	list<int> nbrs;

	Node(int data)
	{
		this->data=data;
	}
};

class Graph
{
	unordered_map<int,Node*>m;
public:
	Graph(vector<int>arr)
	{
		for(auto number:arr)
		{
			m[number]=new Node(number);
		}
	}

	void addEdge(int i,int j,bool undir=true)
	{
		m[i]->nbrs.push_back(j);
		if(undir)
		{
			m[j]->nbrs.push_back(i);
		}
	}

	void printAdjLsit()
	{
		for(auto p:m)
		{
			cout<<p.first<<"	";
			Node* node=p.second;
			//Node list traverse
			for(auto entry : node->nbrs)
			{
				cout<<entry<<" ";
			}
			cout<<endl;
		}
	}
	
};

int main()
{
	std::vector<int> v{10,20,30,40};
	Graph g(v);

	g.addEdge(10,20);
	g.addEdge(20,30);
	g.addEdge(30,40);
	g.addEdge(10,40);
	g.printAdjLsit();
	return 0;
}