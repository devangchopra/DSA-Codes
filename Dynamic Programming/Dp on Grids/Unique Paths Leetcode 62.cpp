class Solution {
public:  

    
    int uniquePathss(int m, int n,vector<vector<int>>& dp) {
        if(m==0 or n==0){
            return 1;
        }
        if(m==0 and n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        return dp[m][n]=uniquePathss(m-1,n,dp)+uniquePathss(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        int x= 105;
        vector<vector<int>> dp(x ,vector<int>(x ,-1));
        return uniquePathss(m-1,n-1,dp);
    }
};