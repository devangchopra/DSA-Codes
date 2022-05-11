#include <bits/stdc++.h>
using namespace std;

class graph {
public:
	int V;
	list<int>* l;

	graph(int v) {
		this->V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	vector<int> bfs(int source, int target) {
		bool* visited = new bool[V] {0};
		visited[source] = true;
		queue<int>q;
		q.push(source);

		int* dist = new int[V];
		int* parent = new int[V] {0};

		for (int i = 0; i < V; i++) {
			dist[i] = -1;
		}

		dist[source] = 0;
		parent[source] = source;

		while (q.empty() == false) {
			int f = q.front();
			q.pop();

			for (auto& nbr : l[f]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					//before visiting i need to make changes in the dist as well as the parent array
					dist[nbr] = dist[f] + 1;
					parent[nbr] = f;
				}
			}
		}

		vector<int>v;

		if (target != -1) {
			int temp = target;
			while (temp != source) {
				v.push_back(temp);
				temp = parent[temp];
			}
			v.push_back(source);
		}
		return v;

	}
};
vector<int> shortestPath( vector<pair<int, int>> edges , int n , int m, int s , int t) {
	// Write your code here
	graph g(n + 1);
	for (auto& p : edges) {
		g.addEdge(p.first, p.second);
	}
	vector<int>ans = g.bfs(s, t);
	reverse(ans.begin(), ans.end());
	return ans;

}

int main() {
	vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
	int n = 4, m = 4;
	int s = 1, t = 4;
	vector<int>ans = shortestPath(edges, n, m, s, t);
	for (auto& i : ans) {
		cout << i << " ";
	}
}