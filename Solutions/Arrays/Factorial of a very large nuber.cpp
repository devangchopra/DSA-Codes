class Solution {
public:
    void multiply(int*a,int& n,int no)
    {
        int carry=0;
        for(int i=0;i<n;i++)
        {
            int product=a[i]*no+carry;
            a[i]=product%10;
            carry=product/10;
        }
        
        while(carry!=0)
        {
            a[n]=carry%10;
            carry=carry/10;
            n++;
        }
    }
    vector<int> factorial(int number){
        // code here
        int * a=new int[500];
        for(int i=0;i<500;i++)
        {
            a[i]=0;
        }
        a[0]=1;
        int n=1;
        for(int i=2;i<=number;i++)
        {
            multiply(a,n,i);
        }
        vector<int>ans;

        for(int i=n-1;i>=0;i--)
        {
            ans.push_back(a[i]);
        }
        return ans;
     
        
        
    }
};