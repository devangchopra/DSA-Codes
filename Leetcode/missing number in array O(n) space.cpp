class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>s;
        for(auto i:nums)
        {
            s.insert(i);
        }
        int ans=0;
        for(int i=0;i<=nums.size();i++)
        {
            if(!(s.find(i)!=s.end()))
            {
                ans=i;
                break;
            }

        }

        return ans;
    }
};