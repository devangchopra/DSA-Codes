class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

        int kthSmallest(int arr[], int l, int r, int k)
        {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<r+1;i++)
        {
            pq.push(arr[i]);
        }
        
        int temp=1;
        
        
        
        while(temp<=k-1)
        {
            pq.pop();
            temp++;
        }
        int x=pq.top();
        return x;
    }
    
};

//--------------------------------------------------
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        sort(arr,arr+(r+1));
        return arr[k-1];
    }
};