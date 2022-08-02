class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            
            if(nums[i]==0){
                continue;
            }
            
            for(int j=i+1;j<n;j++){
                nums[j] = nums[j]-nums[i];
            }
            count++;
            nums[i] = 0;
        }
        return count ;
    }
};