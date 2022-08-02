class Solution {
public:
  bool isvalid(vector<vector<bool>>& vis, int x, int y, int n, vector<vector<int>>& grid) {
    if (x<0 or y<0 or x >= n or y >= n) {
      return false;
    }

    if (grid[x][y] == 1 or vis[x][y] == true) {
      return false;
    }

    return true;
  }



  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    //Base Conditions
    if (grid[0][0] == 0 and n == 1) {
      return 1;
    }
    if (grid[0][0] == 1 or grid[grid.size() - 1][grid.size() - 1] == 1) {
      return - 1;
    }

    //Directions : 8 directions
    vector<pair<int, int>> dir{{ -1, -1}, { -1, 0}, { -1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0},  {1, 1}};

    queue<pair<int, int>>q;
    q.push({0, 0});

    //Visited Array
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    vis[0][0] = true;

    int count = 0 ;

    while (q.empty() == false) {
      count++;

      int x = q.size();
      //take out all the nbrs together to get the minimum distance
      for (int i = 0; i < x; i++) {

        auto p = q.front();
        q.pop();

        for (auto& d : dir) {
          int x = p.first + d.first;
          int y = p.second + d.second;

          if (x == n - 1 && y == n - 1) {
            return count + 1;
          }

          if (isvalid(vis, x, y, n, grid)) {
            q.push({x, y});
            vis[x][y] = true;
          }

        }

      }
    }

    return -1;


  }
};