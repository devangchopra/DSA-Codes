// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
       int one=0;
       int two=1;
       int count=0;
       while(one<n and two<n-1)
       {
           int ans=A[one]+A[two];
           ans=X-ans;
           for(int i=0;i<n;i++)
           {
               if(A[i]==ans and i!=one and i!=two) 
               {
                   count++;
               }          
           }
           one++;
           two++;
           if(count>=1)
           {
               break;
           }
       }
       return count;
    
    }


};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends