class Solution {
public:
    vector<int> countBits(int n) {       
        
    vector<int>output(n+1);
        
    output[0]=0;
        
    for(int i=1;i<=n;i++)
    {
        output[i]=output[i/2]+i%2;
    }   
        
    return output;
        
    }
};