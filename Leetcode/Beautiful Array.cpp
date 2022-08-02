class Solution {
public:
    vector<int> beautifulArray(int n) {
    	//n
    	//Start from the initial
    	vector<int>v;
    	v.push_back(1);

    	//we have to consider till n
    	//The vector is behaving dynamically

    	while(v.size()<n)
    	{
    		vector<int>temp;

    		for(auto element:v)
    		{
    			//Odd
    			if(2*element-1<=n)
    			{
    				temp.push_back(2*element-1);
    			}
    		}

    		for(auto element:v)
    		{
    			//even
    			if(2*element<=n)
    			{
    				temp.push_back(2*element);
    			}
    		}

    		v = temp;
    	}

    	return v;
        
    }
};