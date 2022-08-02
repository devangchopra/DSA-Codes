class Solution{
    public:
    long long int md=1e9+7;
    int Maximize(int a[],int n)
    {
        // Complete the function
        sort(a,a+n);
        long long int product=0;
        for(long long int  i=0;i<n;i++)
        {
            product=product+(a[i]*i);
        }
        return product%md;
    }
};

//long long int concept

//at (vector) , push back and [] not for insertion