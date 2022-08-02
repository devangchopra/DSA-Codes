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

bool ispallindrome(string s) {
	string temp = s;
	string temp2 = temp;
	reverse(temp.begin(), temp.end());
	if (temp == temp2) {
		return true;
	}
	return false;
}

void fun() {
	string s;
	cin >> s;
	int n = s.size();
	if (n == 1) {
		cout << "Yes" << endl;
		return;
	}
	if (s[0] == s[n - 1] and ispallindrome(s)) {
		cout << "Yes" << endl;
		return;
	}
	else {
		int count = 0;
		while (s[0] != s[s.size() - 1]) {
			s.pop_back();
			count++;
		}

		if (s.size() == 1) {
			cout << "No" << endl;
			return;
		}
		if (ispallindrome(s)) {
			cout << "Yes" << endl;
			return;
		}
		cout << "No" << endl;
		return;
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