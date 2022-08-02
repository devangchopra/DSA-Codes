vector<vector<int>>ans;

int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, vector<vector<int>>& maze , vector<vector<int>>& visited) {
  if (x<0 or y<0 or x >= n or y >= n or maze[x][y] == 0 or visited[x][y] == 1) {
    return false;
  }
  return true;
}

void fxn(vector<vector<int>>& maze , int i, int j, int n, vector<vector<int>>& visited) {
  //Base Case
  if (i == n - 1 and j == n - 1) {
    visited[i][j]=1;
    vector<int>l;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        l.push_back(visited[i][j]);
      }
    }
    ans.push_back(l);
    return;
  }
  if (isValid(i, j, n, maze, visited) == false) {
    return;
  }
  visited[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int xx = i + dx[k];
    int yy = j + dy[k];
    fxn(maze, xx, yy, n, visited);
    //one path one inclusion
  }
  visited[i][j] = 0;
  return;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n) {
  // Write your code here.
  //starting point 0,0
  vector<vector<int>>visited(n, vector<int>(n, 0));
  fxn(maze, 0, 0, n, visited);
  return ans;
}