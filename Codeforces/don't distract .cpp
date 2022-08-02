#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<char>v;
        for(int i=0;i<n;i++) 
        {
            char x;
            cin>>x;
            v.push_back(x);
        }
        vector<char>v1;

        for(int i=0;i<n-1;i++)
        {
            if(v[i]!=v[i+1])
            {
                v1.push_back( v[i]);
            }
            
        }
        v1.push_back(v[n-1]);

        set<int>s;
        //cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();i++) 
        {
            s.insert(v1[i]);
        }

        if(s.size()==v1.size())
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}