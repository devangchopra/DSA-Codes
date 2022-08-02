#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int a[N][N];
int n, m;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};


void flood_fill(int x, int y)
{
	a[x][y] = 0;
	//4 nbr consideration
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		//Out of bound check
		if (xx >= 0 and xx < n and yy >= 0 and yy < m and a[xx][yy] == 1)
		{
			flood_fill(xx, yy);
		}
	}

	return;

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}

	int total = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == 1)
			{
				total++;
				//Visit it nbrs and flood fill them
				flood_fill(i, j);
			}
		}
	}

	cout << total << endl;

}