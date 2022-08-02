#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        
        
        for(int i=0;i<s.length()-1;i++)
        {
            if(i%2==0)
            {
                
                    int val=int(s[i]);
                    //cout<<"This is s[i]"<<s[i]<<" "<<"and this is val"<<" "<<val<<endl;
                    
                    //cout<<"Yeh hai"<<"   "<<int(s[i+1])<<endl;


                    val=val+(int(s[i+1])-48);
                    //cout<<"This is val+s[i+1]"<<" "<<val<<endl;

                    s[i+1]=char(val);
                    //cout<<"this is char(val)"<<" "<<char(val)<<endl;
 
            }
            
        }
        
        return s;
    }
};

int main()
{
    string s="a1b2c3d4e";
    Solution obj;
    obj.replaceDigits(s);
    
}