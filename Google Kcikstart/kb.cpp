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
//Use endl wisely buffer flush
#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void fun(int cn) {
	int d, n, k;
	cin >> d >> n >> k;
	vector<vector<int>>v;
	for (int i = 0; i < n; i++) {
		vector<int>temp(3);
		for (auto& i : temp) {
			cin >> i;
		}
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), greater<vector<int>>());
	int ans = 0;
	for (int i = 0; i < d; i++) {
		int temp = 0;
		int t = k;
		for (int j = 0; j < n; j++) {
			if (t) {
				if (v[j][1] <= i + 1 and v[j][2] >= i + 1) {
					temp += v[j][0];
					t--;
				}
			}
		}
		ans = max(temp, ans);
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
