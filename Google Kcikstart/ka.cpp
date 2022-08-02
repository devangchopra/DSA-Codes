#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int 					long long int
#define ld 					long double
#define mod 				1e9+7
#define ps(x,y)   			fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>>
#define endl        		"\n"
#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void fun(int cn) {
	int n;
	cin >> n;
	string s;
	cin >> s;

	ordered_set st;
	vector<int>p;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			st.insert(i);
			p.push_back(i);
		}
	}
	int total = st.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			continue;
		}
		int temp = INT_MAX;
		int x = st.order_of_key(i);
		if (x == 0) {
			auto it = st.begin();
			ans += (*it);
			continue;
		}
		temp = min(temp, abs(i - p[x - 1]));
		int y = total - x;
		if (y != 0) {
			temp = min(temp, abs(i - p[x]));
		}
		ans += temp;
	}
	cout << "Case #" << cn << ":" << " " << ans << endl;
}

int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	int cn = 0;
	while (t--)
	{
		cn++;
		fun(cn);

	}
	return 0;
}
