class Solution {
public:
    int minFlipsMonoIncr(string s) {

    	int len = s.size();

    	int number_of_ones = 0;

    	int changes  = 0;

    	for(auto c:s)
    	{
    		if(c=='0')
    		{
    			if(number_of_ones==0)
    			{
    				//do nothing
    			}
    			else
    			{
    				changes++;
    			}
    		}

    		else
    		{
    			//c->1
    			number_of_ones++;
    		}

    		changes=min(changes,number_of_ones);
    		//Either change all one or change all zero
    	}

    	return changes;
        
    }
};