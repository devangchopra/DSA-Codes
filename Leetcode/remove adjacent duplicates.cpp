class Solution {
public:
    string removeDuplicates(string s) {

    	stack<char>temp;

    	string ans="";

    	int n= s.size();

    	if(s.size()<=1)
    	{
    		return s;
    	}

    	temp.push(s[0]);

    	for (int i=1;i<n;++i)
    	{
    		if(!temp.empty())
        	{
                if(temp.top()==s[i])
                    temp.pop();
            	else
                	temp.push(s[i]);
        	}   
         	else
             	temp.push(s[i]);
    	}

    	while(temp.empty()==false)
    	{
    		ans+=temp.top();
    		temp.pop();
    	}
        reverse(ans.begin(),ans.end());
    	return ans;

        
    }
};