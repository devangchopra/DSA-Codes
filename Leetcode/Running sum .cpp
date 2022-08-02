#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>v;
        int x=nums[0];
        v.push_back(x);
        
        
        
        for(int i=1;i<nums.size();i++)
        {
            x=x+nums[i];
            v.push_back(x);
        }
        return v;


        
    }
};