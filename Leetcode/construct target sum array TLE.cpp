#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& target) {
    	//Edge case
    	if(target.size()==1)
    	{
    		if(target[0]!=1)
    		{
    			return false;
    		}
    	}

    	else
    	{
    		
    		
    		int maxi=*max_element(target.begin(),target.end());
    		while(maxi!=1)
    		{
    			int sum=0;
	    		for (int i = 0; i < target.size(); ++i)
	    		{
	    			sum+=i;
	    		}
	    		sum=sum-maxi;

	    		if(target[target.size()-1]-sum>0)
	    		{
	    			target[target.size()-1]=target[target.size()-1]-sum;
	    		}
	    		else
	    		{
	    			return false;
	    		}

	    		}
	    		maxi=*max_element(target.begin(),target.end());    	
	    	}
	    	return true;         
    }
};