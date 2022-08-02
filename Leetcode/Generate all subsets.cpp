#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> powerset;
    void generate(vector<int> &subset,int i,vector<int>nums)
    {
        //Base Condition
        if(i==nums.size())
        {
            powerset.push_back(subset);
            return;
        }

        //Not Include and call the leftsubtree
        generate(subset,i+1,nums);

        //Include the i and call the right subtree
        subset.push_back(nums[i]);
        generate(subset,i+1,nums);
        //Complete the right subtreee
        subset.pop_back();
        //parent should not encounter the changes that are done for the child trees
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        
        generate(v,0,nums);
        
        return powerset;
        
    }
};