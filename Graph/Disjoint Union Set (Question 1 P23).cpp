//Question : 
//implement disjoint set union data structure. you have to perform queries of two types:
//P 23 

#include <bits/stdc++.h>
using namespace std;
//As v=10^5
#define sze 100001

int find(int i, vector<int>& parent)
{
	if (parent[i] == -1)
		return i;

	return parent[i] = find(parent[i], parent);
}

/*
int find(int x, vector<int>&parent)
{
	while (x != parent[x])
	{
		return parent[x] = find(parent[x], parent);
	}
	return x;
}*/

void unite_sets(int u, int v, vector<int>& parent, vector<int>& rank)
{
	int s1 = find(u, parent);
	int s2 = find(v, parent);

	if (s1 == s2)
	{
		//Do nothing
		return;
	}
	if (rank[s1] > rank[s2])
	{
		swap(s1, s2);
	}
	parent[s1] = s2;
	rank[s2] += rank[s1];
	return;
}

vector<bool> DSU(vector<vector<int>>query)
{
	int n = query.size();
	vector<int>parent(sze);
	vector<int>rank(sze);

	iota(parent.begin(), parent.end(), -1);
	iota(rank.begin(), rank.end(), 1);

	vector<bool>ans;

	for (int i = 0; i < n; i++)
	{
		int x = query[i][0];
		int u = query[i][1];
		int v = query[i][2];

		if (x == 1)
		{
			unite_sets(u, v, parent, rank);
		}
		else
		{
			int s1 = find(u, parent);
			int s2 = find(v, parent);
			cout<<s1<<" "<<s2<<endl;
			if (s1 == s2)
			{
				ans.push_back(true);
			}
			else
			{
				ans.push_back(false);
			}
		}
	}

	return ans;
}