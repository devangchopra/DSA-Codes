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
	vector<vector<int>> matrix(n, vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> matrix[i][j];
		}
	}
	map<int, int>mp;
	for (int i = 0; i <= 4; i++) {
		mp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (matrix[i][j] == 1) {
				mp[j]++;
			}
		}
	}
	int count = 0, half = n / 2;
	vector<int>days;
	bool possible = false;
	for (auto& p : mp) {
		if (count == 2) {
			possible = true;

		}
		if (p.second >= half) {
			count++;
			days.push_back(p.first);
		}
	}
	if (possible == false) {
		cout << "NO" << endl;
		return;
	}
	count = 0;
	for (int i = 0; i < days.size(); i++) {
		bool x = true;
		for (int j = 0; j < n; j++) {
			if (matrix[j][days[i]] != 1) {
				x = false;
				break;
			}
		}
		if (x == true) {
			count++;
		}
	}
	if (count >= 2) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
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
