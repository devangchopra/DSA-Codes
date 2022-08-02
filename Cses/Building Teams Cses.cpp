#include <bits/stdc++.h>
using namespace std;
bool dfs_helper(int node, int parent, int color, vector<int> graph[], vector<int>& visited) {
	visited[node] = color;
	for (auto nbr : graph[node]) {
		if (visited[nbr] == 0) {
			bool subprob = dfs_helper(nbr, node, 3 - color, graph, visited);
			if (subprob == false) {
				return false;
			}
		}
		else if (nbr != parent and color == visited[nbr]) {
			return false;
		}

	}
	return true;
}

bool dfs(int node, vector<int> graph[], vector<int>& visited) {
	int color = 1;
	bool ans = dfs_helper(node, -1, color, graph, visited);
	return ans;
}

int main()
{
		// freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> graph[n + 1];
	vector<int> visited(n + 1, 0);

	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bool x = true;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			x = dfs(i, graph, visited);
			if (x == false) {
				break;
			}
		}
	}
	if (!x) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << " ";
	} cout << endl;




	return 0;
}