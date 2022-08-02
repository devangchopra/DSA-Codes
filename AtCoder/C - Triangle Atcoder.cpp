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

bool valid(vector<pair<int, int>>&v, int i, int j, int k) {
	if ((v[j].first - v[i].first) * (v[k].second - v[i].second) -
	        (v[k].first - v[i].first) * (v[j].second - v[i].second) != 0)
	{
		return true;
	}
	return false;
}
void fun() {
	int n;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (auto& i : v) {
		cin >> i.first >> i.second;
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (valid(v, i, j, k)) {
					count++;
				}
			}
		}
	}
	cout << count << endl;
	return;
}

int32_t main() {
	fastio;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	fun();
	return 0;
}
