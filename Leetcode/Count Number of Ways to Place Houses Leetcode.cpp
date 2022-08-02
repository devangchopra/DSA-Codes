class Solution {
public:
    const long long int mod = 1e9 + 7;
    int dp[10001];
    int dfs(int i,int n){
        if(i >= n) return 1; //if plots filled return 1
        
        if(dp[i] != -1) return dp[i];
		
        int place =dfs(i+2,n); //if placed try to jump on +2 idx because adj not supported
        
        int notplace = dfs(i+1,n); //not placed try to place +1 idx
        
        return dp[i] = (place%mod+notplace%mod)%mod;
    }
    
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = dfs(0,n) % mod;
        return (ans%mod * ans%mod) % mod;
    }
};