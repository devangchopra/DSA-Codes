#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;  
    long long int i = 3, count, c;
    cout<<2<<endl;
    for(count = 2; count <= n; i++)  
    {
        for(c = 2; c < i; c++)
        {
            if(i%c == 0)
                break;
        }

        if(c == i)  
        {
            cout<<i<<endl;
            count++;    
        }

    }
    
    return 0;
}