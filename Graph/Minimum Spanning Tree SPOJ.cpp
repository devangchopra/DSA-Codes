#include <bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	vector<pair<int, int>>* l;

public:
	graph(int n)
	{
		this->V = n;
		l = new vector<pair<int, int>> [V];
	}

	void addEdge(int x, int y, int w)
	{
		l[x].push_back({y, w});
		l[y].push_back({x, w});

		//Node , Weight
	}

	int prim_mst()
	{
		int ans = 0;
		bool* visited = new bool[V]{0};

		priority_queue < pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> Q;
		//First entry sort
		//Weight , Node

		//First Node
		Q.push({0, 1});

		while (Q.empty() == false)
		{
			auto best = Q.top();
			Q.pop();

			int to_vertex = best.second;
			int weight = best.first;

			if (visited[to_vertex] == 1)
			{
				//Do nothing
				//I do not have tp go back
				continue;
			}

			ans += weight;
			visited[to_vertex] = true;

			for (auto nbr : l[to_vertex])
			{
				if (!visited[nbr.first])
				{
					Q.push({nbr.second, nbr.first});
				}
			}

		}

		return ans;

	}
};


int main()
{

	int n, m;
	cin >> n >> m;

	graph g(n + 1);

	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;

		g.addEdge(x, y, w);

	}

	int ans = g.prim_mst ();

	cout<<ans<<endl;

}
