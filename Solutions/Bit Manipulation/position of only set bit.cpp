class Solution {
  public:
    int findPosition(int N) {
        // code here
        int mask=1;
        
        int counter=1;
        
        if(N==0)
        {
            return -1;
        }
        
        if(N==1)
        {
            return 1;
        }
        if((N&(N-1))==0)
        {
            while(N)
            {
                if(N & mask)
                {
                    return counter;
                }
                
                N=N>>1;
                counter++;
            }
        }
        else if((N&(N-1))!=0)
        {
            return -1;
        }
        
    }
};
