#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fun(ll cn) {

	ll n;
	cin >> n;
	string s;
	cin >> s;
	if (n == 1) {
		cout << "Case #" << cn << ":" << " " << 0 << endl;
		return;
	}
	ll changes = 0;
	if (s[0] == 'X') {
		bool c = false;
		for (ll i = 1; i < s.size(); i++) {
			if (s[i] == 'O' and c==false) {
				changes++;
				c = true;
				continue;
			}
			else if (s[i] == 'X' and c == true) {
				changes++;
				c = false;
				continue;
			}

		}
	}
	else if (s[0] == 'O') {
		bool c = false;
		for (ll i = 1; i < s.size(); i++) {
			if (s[i] == 'X' and c==false) {
				changes++;
				c = true;
				continue;
			}
			else if (s[i] == 'O' and c == true) {
				changes++;
				c = false;
				continue;
			}

		}
	}
	else {
		ll cnt_O = 0;
		ll cnt_X = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == 'O') {
				cnt_O++;
			}
			else if (s[i] == 'X') {
				cnt_X++;
			}
		}

		if (cnt_X > cnt_O) {
			//Start with X hand i.e left hand
			bool c = false;
			for (ll i = 1; i < s.size(); i++) {
				if (s[i] == 'O' and c==false) {
					changes++;
					c = true;
					continue;
				}
				else if (s[i] == 'X' and c == true) {
					changes++;
					c = false;
					continue;
				}

			}
		}
		else {
			//Start with O hand i.e. right hand
			bool c = false;
			for (ll i = 1; i < s.size(); i++) {
				if (s[i] == 'X' and c==false) {
					changes++;
					c = true;
					continue;
				}
				else if (s[i] == 'O' and c == true) {
					changes++;
					c = false;
					continue;
				}

			}

		}
	}
	cout << "Case #" << cn << ":" << " " << changes << endl;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("weak_typing_chapter_1_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	ll cn = 0;
	while (t--)
	{
		cn++;
		fun(cn);
	}

	return 0;
}