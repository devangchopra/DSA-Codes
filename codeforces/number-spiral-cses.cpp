#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ntc;
    cin >> ntc;
    while (ntc--)
    {
        ll x ,y;
        cin>>x>>y;
        if (x < y)
        {
            if (y % 2 == 1)
            {
                cout << (y * y) - x + 1 << endl;
            }
            else
            {
                cout << (y - 1) * (y - 1) +  x  << endl;
            }
        }
        else
        {
            if (x % 2 == 0)
            {              
                cout << (x * x) - y + 1 << endl;
            }
            else
            {
                cout << (x - 1) * (x - 1) +y << endl;
            }
        }
    }
    return 0;
}
