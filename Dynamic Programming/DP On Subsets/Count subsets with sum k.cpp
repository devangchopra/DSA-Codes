Count subsets with sum k

#include<bits/stdc++.h>
int dp[100][5000];
int count_subset_sum(vector<int>& arr,int n,int target , int index){

    //Base condition
    if(target == 0){
        return 1;
    }
    if(index == 0){
        return arr[index] == target;
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

    int opn1 = 0;
    if(arr[index] <= target){
        opn1 = count_subset_sum(arr,n,target-arr[index],index-1);
    }

    int opn2 = count_subset_sum(arr,n,target,index-1);

    return dp[index][target] = opn2 + opn1;

}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    memset(dp,-1,sizeof(dp));
    return count_subset_sum(num,num.size(),tar,num.size()-1);
}
