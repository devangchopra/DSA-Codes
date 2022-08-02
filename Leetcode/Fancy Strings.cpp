class Solution {
public:
    string makeFancyString(string s) {
        
        string ans;

        for(int i=0;i<s.size();i++)
        {
        	if(i<=2)
        		ans.push_back(s[i]);

        	else
        	{
        		int p = i-1;
        		int m = i-2;

        		if(s[m]==s[p] and s[p]==s[i])
        			continue;
        		else
        		{
        			ans.push_back(s[i]);
        		}
        	}
        }

        return ans;
    }
};