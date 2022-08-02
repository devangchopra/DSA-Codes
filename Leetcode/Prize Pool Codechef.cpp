#include <bits/stdc++.h>
using namespace std;

void fun() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    ans = ans + x * 10;
    ans += 90 * y;
    cout << ans << endl;
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}
