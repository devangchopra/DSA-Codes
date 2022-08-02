#include<bits/stdc++.h>
//v->100 000
#define sze 100001
using namespace std;

int find(int i, vector<int>& parent)
{
	if (parent[i] == -1)
		return i;

	return parent[i] = find(parent[i], parent);
}

void union_set(int x, int y, vector<int>& parent, vector<int>& rank)
{
	int s1 = find(x, parent);
	int s2 = find(y, parent);

	if (s1 == s2)
	{
		//Do nothing
		return;
	}
	else
	{
		if (rank[s1] > rank[s2])
		{
			swap(s1, s2);
		}
		parent[s1] = s2;
		rank[s2] += rank[s1];
	}
}

bool solve(vector<vector<int>> edges)
{
	vector<int> parent(sze, -1);
	vector<int> rank(sze, 1);

	int n = edges.size();

	for (auto p : edges)
	{
		int u = p[0];
		int v = p[1];
		int s1 = find(u, parent);
		int s2 = find(v, parent);
		if (s1 == s2)
			return false;
		union_set(s1, s2, parent, rank);

	}

	return true;

}