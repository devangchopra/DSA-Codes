class Solution {
public:
	int dfs(vector<vector<int>> &matrix , vector<vector<bool>> &visited , int i , int j , int m , int n)
	{
		visited[i][j]=true;

		int cs=1;

		int dx[] = {1,-1,0,0};
		int dy[] = {0,0,1,-1};

		//Check each neighbour of current node
		for (int k = 0; k < 4; ++k)
		{
			int nx = i+dx[k];
			int ny = j+dy[k];

			if(nx>=0 and nx<m and ny>=0 and ny<n and !visited[nx][ny] and matrix[nx][ny]==1)
			{
				int temp = dfs(matrix,visited,nx,ny,m,n);
				cs = cs+temp;
			} 
		}

		return cs;
	}
    int maxAreaOfIsland(vector<vector<int>>& matrix) {

    	int m = matrix.size();
    	int n = matrix[0].size();

    	vector<vector<bool>> visited (m,vector<bool>(n,false));

    	int largest = 0;

    	//Iterate upon the matrix

    	for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			if(!visited[i][j] and matrix[i][j]==1)
    			{
    				int dfs_ans = dfs(matrix,visited,i,j,m,n);

    				largest = max(largest,dfs_ans);
    			}
    		}
    	}

    	return largest;
        
    }
};