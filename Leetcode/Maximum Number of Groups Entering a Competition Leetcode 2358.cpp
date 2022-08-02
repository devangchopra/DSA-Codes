class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int x = grades.size();
        int temp = 1;
        int ans = 0;
        
        while(x>=temp){            
            ans++;
            x = x - temp;
            temp++;
            
        }
        
        return ans;
    }
};