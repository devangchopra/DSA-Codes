class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto i:nums)
        {
            pq.push(i);
        }
        int ans=0;
        
        for(int i=1;i<=k;i++)
        {
            if(i==k)
            {
                ans=pq.top();
                break;
            }
            else
            {
                pq.pop();
            }
        }
        
        return ans;
    }
};