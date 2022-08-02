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

void fun() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for (auto& i : a) {
		cin >> i;
	}
	set<int>temp;
	while (k--) {
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				temp.insert(i);
			}
		}
		for (auto&i : temp) {
			int prev = INT_MIN, next = INT_MIN;
			if (i == 0) {
				prev = n - 1;
			}
			if (i == n - 1) {
				next = 0;
			}
			if (prev == INT_MIN) {
				prev = i - 1;
			}
			if (next == INT_MIN) {
				next = i + 1;
			}
			a[prev]++;
			a[next]++;
			if (i == n - 1) {
				break;
			}

		}
	}
	int sum = 0;
	for (auto& i : a) {
		sum += i;
	}
	cout << sum << endl;


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
