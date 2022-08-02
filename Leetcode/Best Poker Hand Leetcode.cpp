
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        char c = suits[0];
        bool isflush = true;
        for(auto& i:suits){
        	if(i != c){
        		isflush = false;
        		break;
        	}
        }
        if(isflush){
        	return "Flush";
        }
        unordered_map<int,int>m;
        for(auto& i: ranks){
        	m[i]++;
        }
       
        
        bool isthree = false;
        bool ispair = false;

        for(auto& i:m){
        	if(i.second >= 3){
        		isthree = true;
        		break;
        	}
        	else if(i.second == 2){
        		ispair = true;
        	}
        }

        if(isthree){
        	return "Three of a Kind";
        }

        if(ispair){
        	return "Pair";
        }
        return "High Card";
    }
};