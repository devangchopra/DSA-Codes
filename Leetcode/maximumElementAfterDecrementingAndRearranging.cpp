#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++)
        {
            if(abs(arr[i] - arr[i - 1]) > 1)
            {
                arr[i+1]=arr[i]+1;
            }
             
        
        }
        return *max_element(arr.begin(),arr.end());
        
    }
};