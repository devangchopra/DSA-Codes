#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     bool checkPossibility(vector<int>& nums) {
        int x = 0;
                
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(!(nums[i]<=nums[i+1]))
            {
                x++;
                if(x>1 or ( i-1>0 and i+1<nums.size() and nums[i-2]< nums[i] and nums[i-1]>nums[i+1] ))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;
    vector<int>v{3,4,2,3};
    cout<<obj.checkPossibility(v);
}