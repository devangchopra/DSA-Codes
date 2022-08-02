//If not exaclty 4 digits ? 

class Solution {
public:
    int minimumSum(int num) {
        int t=num;
        vector<int>v;
        while(t){
            int n = t%10;
            v.push_back(n);
            t=t/10;
        }
        sort(v.begin(),v.end());
        int d1=v[0]*10+v[3];
        int d2=v[1]*10+v[2];
        cout<<d1<<" "<<d2<<endl;
        int ans = d1+d2;
        return ans;
    }
};