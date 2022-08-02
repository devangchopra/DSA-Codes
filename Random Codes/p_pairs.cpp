#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>>v;
        
        unordered_map<string,int>m;
        
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            reverse(str.begin(),str.end());
            
            m[str]=i;
        }
       
        for(int i=0;i<words.size();i++)
        {
            if(m.count(words[i])>0)
            {
                
                v.push_back({i,m[words[i]]});
            }
        }

        return v;
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution obj;
    vector<string>s{"a",""};
    obj.palindromePairs(s);
}