#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	int a[n][m], distance[n][m];
	pair<int, int> nearest[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			distance[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < m; jj++) {
						if (abs(i - ii) + abs(j - jj) < distance[ii][jj]) {
							distance[ii][jj] = abs(i - ii) + abs(j - jj);
							nearest[ii][jj] = {i, j};
						}

					}
				}

			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << distance[i][j] << " ";
		} cout << endl;
	}




	return 0;
}