class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        //n ia the size
        //m are the no of children
        long long min=0;
        long long max=m-1;
        long diff =a[max]-a[min];
        for(long long i=0;max<n;i++)
        {
            if((a[max]-a[min])<diff)
            {
                diff=a[max]-a[min];
            }
            min++;
            max++;
        }
        return diff;
    
    }   
};