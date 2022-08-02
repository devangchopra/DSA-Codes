class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);  //O(nlogn)
        for(int i=0;i<n;i++)
        {
            if(a[i]<0 and k>0)
            {
               a[i]=-a[i];
               k--;
            }
        }
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
        }
        int x=*min_element(a,a+n); //O(n)
        if(k%2!=0)
        {
            sum=sum-x;
            sum=sum-x;
        }
        return sum;
    }
};
//iterator --> array do not work