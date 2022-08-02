#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int>& parent)
{
	if (parent[i] == -1)
		return i;

	int s = find(parent[i], parent);
	parent[i] = s;

	return s;
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rank)
{
	int s1 = find(u, parent);
	int s2 = find(v, parent);

	if (s1 == s2)
		return;

	else
	{
		if (rank[s1] > rank[s2])
			swap(s1, s2);

		parent[s1] = s2;
		rank[s2] = rank[s2] + rank[s1];

		return;
	}
}

int makeConnected(int n, vector<vector<int>> connections) {

	vector<int>parent(n, -1);
	vector<int>rank(n, 1);

	int to_make = 0;
	int extra = 0;

	for (auto v : connections)
	{
		int x = v[0];
		int y = v[1];

		int s1 = find(x,parent);
		int s2 = find(y,parent);

		if (s1 == s2)
		{
			extra++;
			continue;
		}
		else
		{
			union_set(s1, s2, parent, rank);
		}
	}

	for (int i = 0; i < n; i++)
	{
		//if there is a set which is
		//still disjoint
		//so we have to make it
		int s = find(i, parent);
		if (s == i)
		{
			to_make++;
		}
	}

	return to_make - 1 <= extra ? to_make - 1 : -1;


}
