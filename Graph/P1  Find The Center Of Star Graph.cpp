/*
// OUTPUT NO. 1

#include <bits/stdc++.h>
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
	Graph(set<int>arr)
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
	vector<vector<int>> v2{{1,2},{5,1},{1,3},{1,4}};
	vector<vector<int>> v{{1,2},{2,3},{4,2}};
	set<int>s;
	for(int i=0;i<v.size();i++)
	{
		s.insert(v[i][0]);
		s.insert(v[i][1]);
	}

	Graph g(s);

	for(int i=0;i<v.size();i++)
	{
		g.addEdge(v[i][0],v[i][1]);
	}
	g.printAdjLsit();
	return 0;
}

*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
    	unordered_map<int,int>m;


    	for(int i=0;i<edges.size();i++)
    	{
    		m[edges[i][0]]++;
    		m[edges[i][1]]++;
    	}

    	int ans=INT_MAX;

    	for(auto p:m)
    	{
    		if(p.first==edges.size())
    		{
    			ans=p.first;
    		}
    	}

    	return ans;


        
    }
};


