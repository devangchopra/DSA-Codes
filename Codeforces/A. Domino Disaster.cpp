#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll 					long long int
#define ld 					long double
#define mod 				1e9+7
#define ps(x,y)   			fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>>
#define endl        		"\n"

#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
//----------------------------------------------------------------------------------------------------------------------
void fun() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (auto i : s) {
		if (i == 'U')
			cout << "D";
		else if (i == 'D')
			cout << "U";
		else
			cout << i;
	}
	cout << endl;
	return;
}




int main()
{
	#ifndef ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	
	ll t;
	cin >> t;
	while (t--) {
		fun();
	}
	return 0;
}