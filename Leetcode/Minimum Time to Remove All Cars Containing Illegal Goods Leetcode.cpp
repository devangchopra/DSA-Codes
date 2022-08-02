class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int>v;
        for(auto it:s){
            if(it=='0'){
                v.push_back(-1);
            }
            else{
                v.push_back(1);
            }
        }
        int mini=0,sum=0;
        for(auto& it:v){
            sum+=it;
            mini=min(sum,mini);
            if(sum>0){
                sum=0;
            }
        }
        return n+mini;
        
    }
};