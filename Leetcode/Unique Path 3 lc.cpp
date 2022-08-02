class Solution {
public:
    vector<pair<int, int>>v = {{0, 1}, { -1, 0}, {0, -1}, {1, 0}};

    void dfs(int i, int j, vector<vector<int>>& grid, int nuze, int* ans, int n, int m) {
        if (i < 0 or j < 0 or i == n or j == m or grid[i][j] == -1 or grid[i][j] == 5) {
            return;
        }

        if (grid[i][j] == 2) {
            if (nuze < 0) {
                //means final stage and all zeroes included
                *ans = *ans + 1;
            }
            return;
        }
        grid[i][j] = 5;
        //making it visited for its nbrs path

        //DFS CALLS : nbrs
        for (auto& p : v) {
            int x = i + p.first;
            int y = j + p.second;
            dfs(x, y, grid, nuze - 1, ans, n, m);

        }
        grid[i][j] = 0;
        //now others can consider this
    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int nuze = 0;
        int rn = 0, cn = 0;
        // for 1 s position

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    nuze++;
                }
                else if (grid[i][j] == 1) {
                    rn = i; cn = j;
                }
            }
        }
        int ans = 0;

        dfs(rn, cn, grid, nuze, &ans, n, m);
        return ans;

    }
};