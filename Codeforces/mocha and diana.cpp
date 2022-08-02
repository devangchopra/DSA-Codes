#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int>& parent)
{
	if (parent[i] == -1)
		return i;

	return parent[i] = find(parent[i], parent);
}

void union_set(int x, int y, vector<int>& parent, vector<int>& rank)
{
	int s1 = find(x, parent);
	int s2 = find(y, parent);

	if (s1 == s2)
	{
		//Do nothing
		return;
	}
	else
	{
		if (rank[s1] > rank[s2])
		{
			swap(s1, s2);
		}
		parent[s1] = s2;
		rank[s2] += rank[s1];
	}
}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m1, m2;
	cin >> n >> m1 >> m2;

	vector<vector<int>> Mocha;
	vector<vector<int>> Diana;

	vector<int> temp;
	while (m1--)
	{
		int u, v;
		cin >> u >> v;
		temp = {u, v};
		Mocha.push_back(temp);
	}

	while (m2--)
	{
		int u, v;
		cin >> u >> v;
		temp = {u, v};
		Diana.push_back(temp);
	}

	vector<int> parent_Mocha(n+1, -1);
	vector<int> rank_Mocha(n+1, 1);

	vector<int> parent_Diana(n+1, -1);
	vector<int> rank_Diana(n+1, 1);




	for (auto p : Mocha)
	{
		int u = p[0];
		int v = p[1];
		int s1 = find(u, parent_Mocha);
		int s2 = find(v, parent_Mocha);
		if (s1 != s2) {
			union_set(s1, s2, parent_Mocha, rank_Mocha);
		}
	}

	for (auto p : Diana)
	{
		int u = p[0];
		int v = p[1];
		int s1 = find(u, parent_Diana);
		int s2 = find(v, parent_Diana);
		if (s1 != s2) {
			union_set(s1, s2, parent_Diana, rank_Diana);
		}
	}

	int EdgesNumber = 0;
	vector<pair<int, int>>ans;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			//Edge i,j
			//If it doesnt results in cycle in both DSU
			//ADD ir
			int MS1 = find(i, parent_Mocha);
			int MS2 = find(j, parent_Mocha);

			int DS1 = find(i, parent_Diana);
			int DS2 = find(j, parent_Diana);

			if (MS1 != MS2 and DS1 != DS2)
			{
				EdgesNumber++;
				union_set(MS1, MS2, parent_Mocha, rank_Mocha);
				union_set(DS1, DS2, parent_Diana, rank_Diana);
				ans.push_back({i, j});

			}
		}
	}

	cout << EdgesNumber << endl;
	if (EdgesNumber)
	{
		for (auto p : ans)
		{
			cout << p.first << " " << p.second << endl;
		}
	}

}

