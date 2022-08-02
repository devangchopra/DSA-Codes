class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    	vector<string>ans;string temp="";int count = 0;
    	for(auto& i:s){
    		count++;
    		temp+=i;
    		if(count==k){
    			ans.push_back(temp);
    			temp="";
    			count=0;
    		}
    	}
    	if(temp!=""){
    		while(count!=k){
    			count++;
    			temp+=fill;
    		}
    		ans.push_back(temp);
    	}
    	return ans;        
    }
};