class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<size-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                ans=nums[i];
                break;
                
            }
        }
        return ans;
        
    }
};