#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int                     long long int
#define ld                     long double
#define mod                 1e9+7
#define ps(x,y)               fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>>
#define endl                "\n"
//Use endl wisely buffer flush
#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void fun32(int head, int tail, string temp, int n, vector<string>& ans) {
    if (ans.size() >= n) {
        return;
    }
    if (temp.size() == 2 * n)
    {
        ans.push_back(temp);
        return;
    }
    if (head < n)
    {
        fun32(head + 1, tail, temp + "(", n, ans);
    }
    if (tail < head)
    {
        fun32(head, tail + 1, temp + ")", n, ans);
    }
}

void fun() {
    int n;
    cin >> n;
    vector<string>ans;
    fun32(0, 0, "", n, ans);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return;
}

int32_t main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        fun();

    }
    return 0;
}
