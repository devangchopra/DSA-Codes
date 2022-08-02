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
	if (k != 0) {
		unordered_map<int, int>mp;
		pair<int, int>p;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				int prev = INT_MAX;
				int next = INT_MAX;

				if (i == 0) {
					prev = n - 1;
					next = i + 1;
				}
				else if (i == n - 1) {
					prev = i - 1;
					next = 0;
				}
				else {
					prev = i - 1;
					next = i + 1;
				}
				p = {prev, next};
				mp.insert(p);
			}
		}


		for (auto i : mp) {

			for (int m = i.first - (k - 1); m <= i.first + (k - 2); m++) {
				int temp = 0;
				if (m < 0) {
					temp = m + n;
				}
				else if (m > n - 1) {
					temp = m - n;
				}
				else {
					temp = m;
				}
				a[temp]++;
			}

			for (int z = i.first + k; z > i.first; z--) {
				int temp = 0;
				if (z < 0) {
					temp = z + n;
				}
				else if (z > n - 1) {
					temp = z - n;
				}
				else {
					temp = z;
				}
				a[temp]++;

			}

			for (int m = i.second - (k - 1); m <= i.second + (k - 2); m++) {
				int temp = 0;
				if (m < 0) {
					temp = m + n;
				}
				else if (m > n - 1) {
					temp = m - n;
				}
				else {
					temp = m;
				}
				a[temp]++;
			}

			for (int z = i.second + k; z > i.second; z--) {
				int temp = 0;
				if (z < 0) {
					temp = z + n;
				}
				else if (z > n - 1) {
					temp = z - n;
				}
				else {
					temp = z;
				}

				a[temp]++;

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
