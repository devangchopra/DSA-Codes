#include <bits/stdc++.h>
using namespace std;
class graph
{
	int V;
	list<pair<int, int>>* l;
public:
	graph(int v)
	{
		this->V = v;
		l = new list<pair<int, int>>[V];
	}
	void addEdge(int u, int v, int w)
	{
		l[u].push_back({v, w});
	}

	vector<int> dijkstra(int source)
	{
		vector<int> dist(V, INT_MAX);
		set<pair<int, int>>s;
		dist[source] = 0;
		s.insert({0, source});

		while (s.empty() == false)
		{
			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first;
			s.erase(it);

			for (auto nbrPair : l[node])
			{
				int nbr = nbrPair.first;
				int CurrentDist = nbrPair.second;

				if (distTillNow + CurrentDist < dist[nbr])
				{
					//If already present delete
					//This step will basically guarentee O(ElogV)
					auto i = s.find({dist[nbr], nbr});
					if (i != s.end())
					{
						s.erase(i);
					}
					dist[nbr] = distTillNow + CurrentDist;
					s.insert({dist[nbr], nbr});
				}
			}
		}

		return dist;

	}
};


class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		graph g(n + 1);
		for (auto v : times)
		{
			g.addEdge(v[0], v[1], v[2]);
		}
		vector<int>ans = g.dijkstra(k);
		ans[0] = 0;
		for (auto i : ans)
		{
			if (i == INT_MAX) {
				return -1;
			}
		}
		int final = INT_MIN;
		for (int i = 1; i < ans.size(); i++)
		{
			final = max(final, ans[i]);

		}
		return final;
	}
};

int main()
{
	vector<vector<int>> times {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
	int n = 4, k = 2;

	vector<vector<int>> times1 {{1, 2, 1}};
	int n1 = 2, k1 = 1;

	vector<vector<int>> times2 {{1, 2, 1}};
	int n2 = 2, k2 = 2;

	Solution obj;
	cout << obj.networkDelayTime(times2, n2, k2) << endl;
}