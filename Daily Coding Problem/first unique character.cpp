/*
This question is asked by Microsoft. Given a string, 
return the index of its first unique character. 
If a unique character does not exist, return -1.

Ex: Given the following strings...

"abcabd", return 2
"thedailybyte", return 1
"developer", return 0
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<int,int>m;
        
        for(auto i:s)
        {
            m[i]++;
        }
        int index  = -1;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==1)
            {
                index = i;
                break;
            }
        }
        return index;
        
    }
};