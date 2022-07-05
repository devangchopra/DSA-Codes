vector<int> maximumsumSubarray(vector<int> &arr , int n){
    //Write your code here

    //Kadanes+Logic
    int maxi=arr[0],endIndex=0,currSum=arr[0];

    for(int i=1;i<n;i++){        
        currSum = max(arr[i],currSum+arr[i]);
        if(currSum>maxi){
            maxi=currSum;
            endIndex=i;
        }     
    }

    int startIndex=endIndex;
    //Logic : Traverse from behind and find starting index

    while(startIndex>=0){
        maxi -= arr[i];
        if(maxi==0){
            break;
        }
        startIndex--;
    }

    vector<int>ans;

    for(int i=startIndex;i<=endIndex;i++){
        ans.push_back(arr[i]);
    }

    return ans;

}