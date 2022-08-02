class Solution {
public:
    void reverseString(vector<char>& s) {
        int index=s.size()-1;
        for(int i=0;i<s.size()-1;i++)
        {
            if(index<=i)
            {
                break;
            }
            char temp=s[i];
            s[i]=s[index];
            s[index]=temp;
            index--;
            
        }
    }
};