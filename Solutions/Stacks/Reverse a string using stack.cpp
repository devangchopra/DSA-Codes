//Leetcode 344
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>b;
        for(auto i:s)
        {
            b.push(i);
        }
        
        for(int i=0;i<s.size();i++)
        {
            s[i]=b.top();
            b.pop();
        }
    }
};