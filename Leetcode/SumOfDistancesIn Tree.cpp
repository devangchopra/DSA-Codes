#include <bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	list<int>* l;

public:
	graph(int v)
	{
		this->V = v;
		l = new list<int>[V];
	}
	void addEdge(int u, int v)
	{
		l[u].push_back(v);
		l[v].push_back(u);
	}

	vector<int> bfs()
	{
		queue<int>q;
		bool* visited = new bool[V] {0};

		vector<int> dist(V, 0);
		int* parent = new int[V];

		for (int i = 0; i < V; i++)
		{
			parent[i] = -1;
		}

		q.push(0);
		visited[0] = true;
		parent[0] = 0;

		while (q.empty() == false)
		{
			int f = q.front();
			q.pop();

			for (auto nbr : l[f])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;
					visited[nbr] = true;
				}
			}
		}
		return dist;
	}
};

class Solution {
public:
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

		if (n == 1)
			return {0};

		graph g(n);
		for (auto v : edges)
		{
			g.addEdge(v[0], v[1]);
		}

		vector<int> dist = g.bfs();
		vector<int> ans;
		int final = 0;
		for (int i = 0; i < n; i++)
		{
			final += dist[i];
		}
		ans.push_back(final);

		int temp = n - 1;
		int p = 1;
		while (temp--)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (i != p)
				{
					sum += dist[p] + dist[i];
				}

			}
			ans.push_back(sum);
			p++;
		}

		return ans;
	}
};
int main()
{
	Solution obj;
	int n = 6;
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
	vector<int>ans = obj.sumOfDistancesInTree(n,edges);
	for(auto i:ans)
		cout<<i<<" ";
	cout<<endl;
}