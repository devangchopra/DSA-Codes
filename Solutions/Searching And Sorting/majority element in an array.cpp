class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int n=(nums.size())/2;
        int ans=0;
        for(auto i:m)
        {
            if(i.second>n)
            {
                ans=i.first;
                break;
            }
        }
        return ans;
        
    }
};