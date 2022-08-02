class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    	uonorderd_map<string,vector<string>>m;

    	for(auto s:strs)
    	{
    		string temp = s;
    		sort(temp.begin(),temp.end());

    		m[temp].push_back(s);
    	}

    	vector<vector<string>>ans;

    	for(auto p:m)
    	{
    		vector<string>temp;
    		for(auto s:p.second)
    		{
    			temp.push_back(s);
    		}
    		ans.push_back(temp);
    	}

    	return ans;
        
    }
};



