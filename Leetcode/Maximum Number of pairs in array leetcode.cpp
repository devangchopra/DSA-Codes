class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        unordered_map<int,int>m;
        for(auto& i:nums){
            m[i]++;
        }
        int doubles = 0;
        int singles = 0;
        
       
        
        for(auto& i:m){
           doubles += i.second/2;
            singles += i.second%2;
        }
        
        return {doubles,singles};
        
        
    }
};