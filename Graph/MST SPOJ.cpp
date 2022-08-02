#include<bits/stdc++.h>
using namespace std;

class DSU
{
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2)
		{
			if (rank[s1] > rank[s2])
				swap(s1, s2);
			parent[s1] = s2;
			rank[s2] += rank[s1];
		}
	}

};

class graph
{
	vector<vector<int>> l;
	int v;

public:
	graph(int v)
	{
		this->v = v;
	}
	void addEdge(int x, int y, int w)
	{
		l.push_back({w, x, y});
		//We want sorting on basis of w

	}

	int kruskal_mst()
	{
		int ans = 0;
		sort(l.begin(), l.end());

		DSU d(v);

		for (auto edge : l)
		{
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			if (d.find(x) != d.find(y))
			{
				d.unite(x, y);
				ans += w;
			}
		}

		return ans;
	}
};

/*
int MST(int n, vector<vector<int>> edges)
{
	graph g(n + 1);

	for (auto v : edges)
	{
		g.addEdge(v[0] - 1, v[1] - 1, v[2]);
	}

	return g.kruskal_mst();
}*/


int main()
{
	int n, m;
	cin >> n >> m;

	graph g(n + 1);

	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;

		g.addEdge(x,y,w);
	}

	cout<<g.kruskal_mst()<<endl;
}