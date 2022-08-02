#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& r) 
    {

    	int n=r.size();
        int count=0;
        
        if(n<1)
        {
            return n;
        }
        else if(n==1)
        {
            count=count+n;
            
        }
        else if(n==2)
        {
            count=count+n;
            if(r[0]<r[1])
            {
                count++;
            }
            else if(r[0]>r[1])
            {
                count++;
            }
        }
        
        else
        {
            vector<int>l2r(n,1);
            vector<int>r2l(n,1);
            for(int i=1;i<n;i++)
            {
                if(r[i]>r[i-1])
                {
                    l2r[i]=l2r[i-1]+1;
                }
            }

            for(int i=n-2;i>=0;i--)
            {
                if(r[i]>r[i+1])
                {
                    r2l[i]=r2l[i+1]+1;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                count+=max(r2l[i],l2r[i]);
            }
        }

    	

    	return count;

    }  
};