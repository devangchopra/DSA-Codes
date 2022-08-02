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
	string s;
	cin >> s;
	if (s.size() <= 2) {
		cout << "NO" << endl;
		return;
	}
	vector<int> ab;
	vector<int> bc;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			ab.push_back(i);
		}
		if (s[i] == 'B') {
			ab.push_back(i);
			bc.push_back(i);
		}
		else {
			bc.push_back(i);
		}
	}
	sort(ab.begin(), ab.end());
	sort(bc.begin(), bc.end());
	bool possible = true;
	for (int i = 0; i < ab.size() - 1; i++) {
		if (ab[i + 1] - ab[i] == 1) {
			possible = false;
			break;
		}
	}
	for (int i = 0; i < bc.size() - 1; i++) {
		if (bc[i + 1] - bc[i] == 1) {
			possible = false;
			break;
		}

	}
	for (auto i : ab) {
		cout << i << " ";
	} cout << endl;
	for (auto i : bc) {
		cout << i << " ";
	} cout << endl;
	if (possible) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
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
