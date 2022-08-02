class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        string ans="";
        for(i=num.size()-1;i>=0;i--)
        {
            if((num[i]-'0')%2 !=0)
            {
                ans=num.substr(0,i+1);
                break;
            }
        }
        
        return ans;
    }
};