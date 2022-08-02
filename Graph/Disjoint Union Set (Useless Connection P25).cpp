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

vector<int> findUselessConnection(vector<vector<int>> edges) {

	vector<int>parent(1001, -1);
	vector<int>rank(1001, 1);


	vector<int> ans;

	pair<int, int>p;

	for (auto v : edges)
	{
		int x = v[0];
		int y = v[1];

		int s1 = find(x, parent);
		int s2 = find(y, parent);

		cout<<s1<<" "<<s2<<endl;

		if (s1 == s2)
		{
			//Breaking the tree
			p = {x, y};
		}

		else
		{
			union_set(s1, s2, parent, rank);
		}

	}

	ans.push_back(p.first);
	ans.push_back(p.second);

	return ans;

}