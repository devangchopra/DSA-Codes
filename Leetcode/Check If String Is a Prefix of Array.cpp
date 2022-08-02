class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {

    	string ans="";

    	for(auto i:words)
    	{
    		for(auto j:i)
    		{
    			ans.push_back(j);
    		}

    		if(ans==s)
    			return true;
    	}   		

    	return false;        
    }
};