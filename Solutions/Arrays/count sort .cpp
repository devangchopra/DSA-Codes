// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int count[n]={0}; //initializing freq of all elements to zero
        int k=3; //0,1,2
        for(int i=0;i<n;i++)
        {
            count[a[i]]++;     
        }
        
        //now array is a self pointer so i have to change array
        int index=0;
        
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<count[i];j++)
            {
                a[index]=i;
                index++;
            }
        }
      
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends