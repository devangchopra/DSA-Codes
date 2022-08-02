#include <bits/stdc++.h>
using namespace std;

//Solution 1 :
//Bruete and TLE ....2^n combiations

class Solution {
public:
    void kthGrammar(int n, int k) {
        queue<int>q;
        q.push(0);
        int i=1;
        while(i<=n)
        {
            int s=q.size();
            while(s--)
            {
                int temp=q.front();
                q.pop();
                if(temp==0)
                {
                    q.push(0);
                    q.push(1);
                }
                if(temp==1)
                {
                    q.push(1);
                    q.push(0);
                }
            }
            
            i++;
        } 
        vector<int>v;
        while(q.empty()==false)
        {
            int temp=q.front();
            q.pop();
            v.push_back(temp);
        }   
        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
        cout<<v[k-1];
    }
};
int main()
{
    Solution obj;
    obj.kthGrammar(2,2);
}


/******************************************************************************************/

//Soution 2

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)
            return 0;
        if(k%2 == 0) return (kthGrammar(n-1, k/2) == 0)? 1 : 0;
        else return(kthGrammar(n-1, (k+1)/2) == 0)? 0 : 1;
        
    }
};