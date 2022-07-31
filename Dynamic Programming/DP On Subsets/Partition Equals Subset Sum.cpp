Partition Equals Subset Sum

class Solution {
public:

    int dp[205][20005];

    bool subset_sum(vector<int>& nums, int target , int index){
        if(target<0){
            return false;
        }

        if(target == 0){
            return true;
        }

        if(index == 0){
            //no available array but sum is still there
            return nums[index]==target;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        int opn1 = subset_sum(nums,target-nums[index],index-1);
        int opn2 = subset_sum(nums,target,index-1);

        return dp[index][target] = opn2 or opn1;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto& i:nums){
            sum += i;
        }

        if(sum%2 != 0){
            return false;
            //odd : can not divide any how
        }

        memset(dp,-1,sizeof(dp));

        return subset_sum(nums,sum/2,n-1);
        //you can also start with 0 but have 
        //to be careful about the test cases
    }
};