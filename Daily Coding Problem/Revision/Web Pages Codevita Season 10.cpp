#include<bits/stdc++.h>
using namespace std;
#define ll 					long long int
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool reachable = false;
int countA = 0;

class Graph {

	int V;
	list<int>* l;

public:

	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i, int j) {
		l[i].push_back(j);

	}


	void bfs(int source, int endPoint) {
		queue<int>q;

		bool* visited = new bool[V] {0};
		q.push(source);
		visited[source] = true;

		while (!q.empty()) {
			countA++;


			int f = q.front();
			if (f == endPoint) {
				reachable = true;
				break;
			}
			q.pop();

			for (auto nbr : l[f]) {

				if (!visited[nbr]) {

					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

};




void fun() {

	int n;
	cin >> n;
	vector<string>v;

	for (int i = 0; i <= n; i++) {
		string s;
		getline(cin, s);
		v.push_back(s);
	}

	int startPoint, endPoint;
	cin >> startPoint >> endPoint;

	Graph g(n + 1);

	for (int i = 1; i <= n; i++) {
		istringstream ss(v[i]);
		string curr;
		while (ss >> curr) {
			g.addEdge(i, stoi(curr));
		}
	}

	g.bfs(startPoint, endPoint);

	if (reachable == false) {
		cout << -1 << endl;
		return;
	}
	else {
		cout << countA - 1 << endl;
		return;
	}


}


//----------------------------------------------------------------------------------


int main()
{
	fastio;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	fun();
	return 0;
}