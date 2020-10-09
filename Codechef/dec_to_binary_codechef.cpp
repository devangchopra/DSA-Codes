#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    while(n--)
    {
        long long int a;
        cin>>a;
        char res[100];
        itoa(a,res,2);
        cout<<res<<endl;
    }
}