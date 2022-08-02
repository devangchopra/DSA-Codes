class Solution {
public:
    int percentageLetter(string s, char letter) {
        int freq=0;
        int x = s.size();
        for(auto& i:s){
            if(i==letter){
                freq++;
            }
        }
        cout<<freq<<endl;
        int ans = (freq*100/x);
        return ans;
        
    }
};