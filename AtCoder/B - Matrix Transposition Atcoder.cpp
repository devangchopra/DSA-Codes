#include<bits/stdc++.h>
using namespace std;
#define ll 					long long int
#define ld 					long double
#define mod 				1e9+7
#define ps(x,y)   			fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>>
#define endl        		"\n"
//Use endl wisely buffer flush
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

void fun() {
	int n, m;
	cin >> n >> m;

	int a[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int b[m][n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[j][i] << " ";
		} cout << endl;
	}

}


//----------------------------------------------------------------------------------


int32_t main()
{
	fastio;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	fun();
	return 0;
}