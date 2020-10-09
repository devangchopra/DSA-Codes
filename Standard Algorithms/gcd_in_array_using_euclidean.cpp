#include<bits/stdc++.h>
using namespace std;

int __gcd(int a,int b)
{
    if(b==0)
        return a;

    else return gcd(b,a%b);
}

int main()
{
    int ntc;
    cin>>ntc;

    while(ntc--)
    {
        int n,q;
        cin>>n>>q;

        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int prefixgcd[n];

        prefixgcd[0]=a[0];

        for(int i=1;i<n;i++)
        {
            prefixgcd[i] = __gcd(a[i],prefixgcd[i-1]);
        }

        int suffixgcd[n];

        suffixgcd[n-1]=a[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suffixgcd[i] = __gcd(a[i],suffixgcd[i+1]);
        }

        for(int i=0;i<q;i++)
        {
            int l,r;
            cin>>l>>r;
            l--;r--;

            if(l==0)
            {
                cout<<suffixgcd[r+1];
            }
            else if(r==n-1)
            {
                cout<<prefixgcd[l-1];
            }
            else
            {
                cout<<__gcd(prefixgcd[l-1],suffixgcd[r+1]);
            }

            cout<<'\n';
        }
    }

    return 0;
}