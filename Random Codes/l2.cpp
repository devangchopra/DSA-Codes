#include <bits/stdc++.h>
using namespace std;
class Solution {
	vector<vector<int>> ans;
public:
	pair<int, int> dfs(vector<vector<int>> &matrix , vector<vector<bool>> &visited , int i , int j , int m , int n)
	{
		visited[i][j] = true;

		pair<int, int>p;

		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};

		//Check each neighbour of current node
		for (int k = 0; k < 4; ++k)
		{
			int nx = i + dx[k];
			int ny = j + dy[k];

			if (nx >= 0 and nx<m and ny >= 0 and ny < n and !visited[nx][ny] and matrix[nx][ny] == 1)
			{
				p = {nx, ny};
				pair<int, int> temp = dfs(matrix, visited, nx, ny, m, n);
				p = max(p, temp);
			}
		}

		return p;
	}

	vector<vector<int>> findFarmland(vector<vector<int>>& land) {

		if (land.size() == 1 and land[0].size()==1)
		{
			if (land[0][0] == 0)
				return ans;
			else
			{
				ans.push_back({0, 0, 0, 0});
				return ans;
			}
		}

		int m = land.size();
		int n = land[0].size();
        

		vector<vector<bool>> visited (m, vector<bool>(n, false));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] and land[i][j] == 1)
				{
					vector<int>temp;
					temp.push_back(i);
					temp.push_back(j);
					pair<int, int> final  = dfs(land, visited, i, j, m, n);
					
					if (final.first != 0 or final.second != 0) {
						temp.push_back(final.first);
						temp.push_back(final.second);
					}
					else
					{
						temp.push_back(i);
						temp.push_back(j);
					}
					ans.push_back(temp);
				}
			}
		}

		return ans;

	}
};
int main()
{
	vector<vector<int>> land {{1,1,1,1,1,1,1,1,1,1,1,1}};
	Solution obj;
	obj.findFarmland(land);
}