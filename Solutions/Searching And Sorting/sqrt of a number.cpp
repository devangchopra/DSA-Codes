class Solution {
public:
    int mySqrt(int x) {
        long long int low=0;
        long long int high=x;
        long long int mid=0;  // to avoide overflow
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            if(mid*mid==x)
            {
                return mid;
            }
            
            else if(mid*mid<x)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
};