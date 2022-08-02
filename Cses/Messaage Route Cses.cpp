#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> graph[n + 1];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bool* visited =  new bool[n + 1] {0};
	int* distance = new int [n + 1] {0} ;
	int* parent  = new int [n + 1];
	for (int i = 0; i < n + 1; i++) {
		parent[i] = -1;
	}
	queue<int>q;
	q.push(1);
	visited[1] = true;
	parent[1] = 1;
	distance[1] = 0;
	while (q.empty() == false) {
		int f = q.front();
		q.pop();
		for (auto nbr : graph[f]) {
			if (!visited[nbr]) {
				parent[nbr] = f;
				distance[nbr] = distance[f] + 1;
				visited[nbr] = true;
				q.push(nbr);
			}
		}
	}


	if (distance[n] == 0) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << distance[n]+1 << endl;
		int temp = n ;
		vector<int>ans;
		while (temp != 1) {
			ans.push_back(temp);
			temp = parent[temp];
		}
		ans.push_back(1);
		reverse(ans.begin(), ans.end());
		for (auto i : ans) {
			cout << i << " ";
		} cout << endl;
	}


	return 0;
}