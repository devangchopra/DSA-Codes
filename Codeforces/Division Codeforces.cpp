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
	ll x;
	cin >> x;

	if (x >= 1900) {
		cout << "Division 1" << endl;
		return;
	}
	else if (x >= 1600 and x <= 1899) {
		cout << "Division 2" << endl;
		return;
	}
	else if (x >= 1400 and x <= 1599) {
		cout << "Division 3" << endl;
		return;
	}
	else {
		cout << "Division 4" << endl;
		return;
	}


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