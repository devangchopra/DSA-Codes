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
        string stri = to_string(n);
        int count=0;
        for(int i=0;i<=stri.length();i++)
        {
            
            int m=0;
            for(int i=0;i<stri.length()-1;i++)
            {
                if(stri[i]!=stri[i+1])
                {
                    m=1;

                    break;
                }
            }
            if(m==0)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    
}