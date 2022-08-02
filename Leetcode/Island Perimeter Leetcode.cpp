class Solution {
public:

bool valid(int a,int b,int n,int m){
    
    return (a<n&&a>=0 && b<m&&b>=0);
}

void dfs(vector<vector<int>>& grid,vector<vector<bool>> &used,int a,int b,int n,int m,int *k){
    
    if(grid[a][b]==1)
        (*k)+=4;
    
    used[a][b] = true;
    
    int d[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    
    for(int i=0;i<4;i++){
        int newa = a+d[i][0];
        int newb = b+d[i][1];
        
        if(valid(newa,newb,n,m) && grid[newa][newb]==1){
            (*k)--;
            if(!used[newa][newb])
                dfs(grid,used,newa,newb,n,m,k);
        }
        
    }
    
    return;
}


int islandPerimeter(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    
    int perimeter = INT_MIN;
    
    vector<vector<bool>> used(n,vector<bool>(m,false));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int k=0;
            if(grid[i][j]==1 && !used[i][j])
                dfs(grid,used,i,j,n,m,&k);
            
            perimeter = max(perimeter,k);
        }
    }
    
    return perimeter;
}
};