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
	int n;
	cin >> n;
	int* arr = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int x;
	cin >> x;
	int ans = (x / sum);
	if (x / sum > 1) {
		ans = x / sum;
	}
	x = x - (sum * ans);
	ans = ans * n;
	for (int i = 0; i < n; i++) {
		if (x < 0) {
			break;
		}
		ans++;
		x = x - arr[i];
	}
	cout << ans << endl;

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
