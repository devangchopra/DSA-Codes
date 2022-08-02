#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int visited[60][60];
class Solution {
public:

	void floodfill(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor, int n, int m)
	{
		image[sr][sc] = newColor;

		for (int i = 0; i < 4; i++) {
			int srx = sr + dx[i];
			int src = sc + dy[i];

			if (srx >= 0 and srx<n and src >= 0 and src < m and image[srx][src] == oldColor and visited[srx][src] == 0) {
				visited[srx][src] = 1;
				floodfill(image, srx, src, oldColor, newColor, n, m);
			}
		}
		return;

	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

		int n = image.size();
		int m = image[0].size();
		if (sr >= n and sc >= m) {
			return image;
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == sr and j == sc) {
					int oldColor = image[i][j];
					visited[i][j] = 1;
					floodfill(image, sr, sc, oldColor, newColor, n, m);
				}
			}
		}
		for(int i=0;i<60;i++){
			for(int j=0;j<60;j++){
				visited[i][j]=0;
			}
		}
		return image;
	}
};

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution obj;

	vector<vector<int>>image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	int  sr = 1, sc = 1, newColor = 2;



	vector<vector<int>>image2 = {{0, 0, 0}, {0, 0, 0}};
	int sr2 = 0, sc2 = 0, newColor2 = 2;
	vector<vector<int>>ans = obj.floodFill(image2, sr2, sc2, newColor2);

	for (auto& v : image) {
		for (auto& i : v) {
			cout << i << " ";
		} cout << endl;
	}


	return 0;
}