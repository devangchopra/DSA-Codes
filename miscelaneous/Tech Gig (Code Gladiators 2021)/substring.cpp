#include<bits/stdc++.h>
using namespace std;
int main()
{
    string v;
    cin>>v;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        int x=0;
        for(int i=0;i<v.size();i++)
        {
            if(s[x]==v[i])
            {
                x++;
            }
        }
        if(x==s.size())
        {
            cout<<"POSITIVE"<<endl;
        }
        else{
            cout<<"NEGATIVE"<<endl;
        }
    }
}