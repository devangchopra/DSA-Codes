class Solution {
public:
    string largestGoodInteger(string num) {
    	string ans="";
    	//"6777133339"
    	//group of 3
            	if(num.size()==3){
    		if(num[0]==num[1] and num[1]==num[2]){
    			return num;
    		}
    	}
    	int x=num.size()-3;
    	for(int i=0;i<=x;i++){
    		if(num[i]==num[i+1] and num[i+1]==num[i+2]){
    			string tmp;
                tmp.push_back(num[i]);
                tmp.push_back(num[i+1]);
                tmp.push_back(num[i+2]);
    			ans=max(ans,tmp);
    		}
    	}
        return ans;
    }
};