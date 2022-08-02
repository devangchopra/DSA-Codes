#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	class Graph {

		vector<pair<int, int> > *l;
		int V;

	public:
		Graph(int n) {
			V = n;
			l = new vector<pair<int, int> >[n];
		}

		void addEdge(int x, int y, int w) {
			l[x].push_back({y, w});
			l[y].push_back({x, w});
		}

		int prim_mst() {
			priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > Q;
			bool * vis = new bool[V] {0};
			int ans = 0;
			Q.push({0, 0});

			while (!Q.empty()) {
				auto best = Q.top();
				Q.pop();

				int to = best.second;
				int weight = best.first;

				if (vis[to]) {
					continue;
				}
				ans += weight;
				vis[to] = 1;
				for (auto x : l[to]) {
					if (vis[x.first] == 0) {
						Q.push({x.second, x.first});
					}
				}
			}
			return ans;
		}

	};


	int minCostConnectPoints(vector<vector<int>>& points) {

		int n = points.size();
		Graph g(n + 1);

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int dx = abs(points[i][0] - points[j][0]);
				int dy = abs(points[i][1] - points[j][1]);

				int w = dx + dy;
				g.addEdge(i, j, w);
			}
		}

		int ans = g.prim_mst();
		return ans;
	}
};

int main()
{

	Solution obj;


	vector<vector<int>> points {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

	vector<vector<int>> points1 {{3, 12}, { -2, 5}, { -4, 1}};


	cout << obj.minCostConnectPoints(points1);


}