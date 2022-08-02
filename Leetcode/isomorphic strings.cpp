class Solution{
public: 
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
           unordered_map<char, char> stot; 
        unordered_map<char, char> ttos;
        int n=t.size();
        for(int i=0;i<n;i++){
            stot[s[i]]=t[i];
            ttos[t[i]]=s[i];
        }
        
         for(int i=0;i<n;i++){
             if(stot[s[i]]==t[i]&&ttos[t[i]]==s[i]){
                 continue;
             }
             else{
                 return false;
             }
         }
        return true;
        
        
    }
};