
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int x=stoi(s1);
       int y=stoi(s2);
       int ans=x*y;
       string s =to_string(ans);
       return s;

    }

};
int main()
{
    Solution obj;
    cout<<obj.multiplyStrings("33","2");
}
