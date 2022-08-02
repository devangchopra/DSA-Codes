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
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }

        int count =0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int d=v[j]-v[i];
                if(i<j and d==j-i)
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}