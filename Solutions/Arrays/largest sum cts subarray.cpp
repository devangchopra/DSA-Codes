// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int max_sum=0;
        int curr_sum=0;
        for (size_t i = 0; i < n; i++)
        {
            /* code */
            curr_sum=curr_sum+arr[i];
            if(curr_sum>max_sum)
            {
                max_sum=curr_sum;
            }
            if(curr_sum<0)
            {
                curr_sum=0;            
            }
        }
        
        if(max_sum==0)
        {
            max_sum=INT_MIN;
            for (size_t i = 0; i < n; i++)
            {
                /* code */
                if(arr[i]>max_sum)
                {
                    max_sum=arr[i];
                }
            }            
        }
        return max_sum;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends