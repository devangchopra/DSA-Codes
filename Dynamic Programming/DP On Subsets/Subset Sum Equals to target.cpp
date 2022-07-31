//Subset Sum Equals to target


class Solution{   
public:

    int dp[105][10005];

    bool fxn(vector<int>& arr,int sum,int index){
        if(sum<0){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(index == 0){
            return arr[index]==sum;
        }

        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        //Two options : either to include or not include 
        bool opn1 = fxn(arr,sum-arr[index],index-1);
        bool opn2 = fxn(arr,sum,index-1);

        return dp[index][sum] =  opn2 or opn1;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return fxn(arr,sum,n-1);
    }
};