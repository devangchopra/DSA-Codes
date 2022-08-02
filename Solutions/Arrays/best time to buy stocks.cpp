#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int max=INT_MIN, min=INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min)
                min = prices[i];
                //finding minimum
            if((prices[i]-min)>max)
                max=prices[i]-min;
                //finding the diff
        }
        return max;
    }
};


// code for dp as well
