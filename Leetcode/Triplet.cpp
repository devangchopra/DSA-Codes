#include<bits/stdc++.h>
using namespace std;

#define ll 					long long int
#define ld 					long double
#define mod 				1e9+7
#define ps(x,y)   			fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>>
#define endl        		"\n"
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//---------------------------------------------------------------------------------

void fun()
{
	//Code
	ll n;
	cin >> n;
	vector<int>arr(n);
	ll temp;
	for (ll i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	bool possible = true;
	//Even Check
	bool even;
	if (arr[1] % 2 == 0) {
		even = true;
	}
	else {
		even = false;
	}
	for (int i = 2; i < n; i = i + 2) {
		if (even) {
			if (arr[i] % 2 != 0) {
				possible = false;
				break;
			}
		}
		else {
			if (arr[i] % 2 == 0) {
				possible = false;
				break;
			}
		}
	}
	if (!possible) {
		cout << "No" << endl;
		return;
	}
	//Odd Check
	bool odd;
	if (arr[0] % 2 != 0) {
		odd = true;
	}
	else {
		odd = false;
	}
	for (int i = 1; i < n; i = i + 2) {
		if (odd) {
			if (arr[i] % 2 == 0) {
				possible = false;
				break;
			}
		}
		else {
			if (arr[i] % 2 != 0) {
				possible = false;
				break;
			}
		}
	}
	if (possible) {
		cout << "Yes" << endl;
		return;
	}
	cout << "No" << endl;

	return;


}


//----------------------------------------------------------------------------------


int main()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	while (t--)
	{
		fun();

	}
	return 0;
}