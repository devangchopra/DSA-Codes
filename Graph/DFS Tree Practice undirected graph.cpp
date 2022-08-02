#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 1;
vector<int> graph[n];
int visited[n];
int x, y;
bool flag = false;

void dfs(int node, int parent) {
	cout << node << endl;
	visited[node] = 1;
	for (auto i : graph[node]) {
		if (!visited[i]) {
			dfs(i, node);
		}
		else if (i != parent) {
			cout << i << " " << node << endl;
			flag = true;
		}
	}
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> x >> y;
	for (int i = 0; i < y; i++) {
		int m, n;
		cin >> n >> m;
		graph[m].push_back(n);
		graph[n].push_back(m);
	}
	for (int i = 1; i <= x; i++) {
		if (!visited[i]) {
			dfs(i, 0);
		}
	}
	if (flag) {
		cout << "Cycle is present" << endl;
	}
	else {
		cout << "Enjoy!! Not present " << endl;
	}

	return 0;
}