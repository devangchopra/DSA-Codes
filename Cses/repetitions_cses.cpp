#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int best , curr;
    best =0;
    curr =1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
        {
            best = max(best, curr);
            curr = 0;
        }
        curr++;
    }
    best = max(best, curr);
    cout << best;
    return 0;
}