class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        
        while(n>0)
        {
            int last_bit=(n&1);
            count+=last_bit;
            n=n>>1;
            //checking next bit
        }
        return count;
    }
};