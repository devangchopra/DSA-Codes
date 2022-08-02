#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& N) {
        int len = N.size() - 1, end_of_previous_jump = -1, next_point = 0, no_of_jumps = 0;
        for (int i = 0; next_point < len; i++) 
        {
            if (i > end_of_previous_jump) 
            {
                no_of_jumps ++;
                end_of_previous_jump = next_point;
            }
            next_point = max(next_point, N[i] + i);
            
        }
        return no_of_jumps;
    }
};

//This condition is imp

//arr[i]!=0