class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& s1,const string& s2){
           return s1.length()>s2.length(); 
        });
        // mapping of string --> unique number
        unordered_map<string,int> index;
        int n = words.size();
        
        // assign every string a unique number
        for(int i=0;i<n;i++)
            index[words[i]] = i;
        
        int ans = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                string new_string = words[i].substr(0,j)+words[i].substr(j+1);
                if(index.count(new_string)){
                    dp[index[new_string]] = max(dp[index[new_string]],1+dp[i]);
                    ans = max(ans,dp[index[new_string]]);
                }
            }
        }
        return ans;
    }
};