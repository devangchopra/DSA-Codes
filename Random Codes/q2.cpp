#include<bits/stdc++.h>
using namespace std;

int funct(int p, int q, int r, int psw)
{
    if (p<0 || q<0 || r<0)
        return 0;
    if (p==1 && q==0 && r==0 && psw==0)
        return 1;
    if (p==0 && q==1 && r==0 && psw==1)
        return 1;
    if (p==0 && q==0 && r==1 && psw==2)
        return 1;
    if (psw==0)
        return funct(p-1,q,r,1) + funct(p-1,q,r,2);
    if (psw==1)
        return funct(p,q-1,r,0) + funct(p,q-1,r,2);
    if (psw==2)
        return funct(p,q,r-1,0) + funct(p,q,r-1,1);
}


int helper(int p, int q, int r)
{
    return funct(p, q, r, 0) + funct(p, q, r, 1) + funct(p, q, r, 2); 
}


int main()
{
    int r,g,t;
    cin>>r>>g>>t;
    cout<<helper(r,g,t);
    return 0;
}
