#include <bits/stdc++.h>
using namespace std;

struct  dsu
{
	vector<int> parent;
	void init (int n)
	{
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
		//also u can use the for loop
	}

	//parent of x
	int find(int x)
	{
		return (x == parent[x] ? x : (parent[x] = find(parent[x])));
	}

	void union_set(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x != y)
		{
			parent[x] = max(parent[x], parent[y]);
			parent[y] = max(parent[x], parent[y]);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;
	int l[q], r[q], c[q];

	for (int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i] >> c[i];
	}

	dsu d;
	d.init(n + 2);
	int res[n + 2] = {};


	//uniting n and n+1 (Easy ho jaega)

	for (int i = q - 1; i >= 0; i--)
	{
		//index -> Right Most non coloured index
		int index = d.find(l[i]);

		while (index <= r[i])
		{
			res[index] = c[i];
			d.union_set(index, index + 1);
			//index ka parent index+1
			//Right most value

			//Jumping on right most non coloured
			index = d.find(index);
		}

	}

	for (int i = 1; i <= n; i++)
	{
		cout << res[i] << endl;
	}

}