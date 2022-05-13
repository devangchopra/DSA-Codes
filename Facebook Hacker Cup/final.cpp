#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fun(ll cn)
{
	string s;
	cin >> s;

	if (s.size() == 1) {
		cout << "Case #" << cn << ":" << " " << 0 << endl;
		return;
	}

	unordered_map<char, int> v;
	unordered_map<char, int> c;

	for (auto i : s) {
		if (i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U') {
			v[i]++;
		}
		else {
			c[i]++;
		}
	}

	multimap<int, char, greater<int>> vowel;
	multimap<int, char, greater<int>> consonant;

	for (auto i : v) {
		vowel.insert({i.second, i.first});
	}

	for (auto i : c) {
		consonant.insert({i.second, i.first});
	}

	if (vowel.size() == 0) {
		ll ans = 0;

		for (auto i : consonant) {
			ans += i.first;
		}
		cout << "Case #" << cn << ":" << " " << ans << endl;
		return;
	}

	if (consonant.size() == 0) {
		ll ans = 0;

		for (auto i : vowel) {
			ans += i.first;
		}
		cout << "Case #" << cn << ":" << " " << ans << endl;
		return;
	}

	char change = '\0';
	ll vowel_to_cons = 0;
	ll cons_to_vowel = 0;

	//VM->CM
	for (auto i : vowel) {
		change = i.second;
		break;
	}
	for (auto i : consonant) {
		vowel_to_cons += i.first;
	}
	for (auto i : vowel) {
		if (i.second != change) {
			vowel_to_cons += (i.first * 2);
		}
	}

	//CM->VM
	for (auto i : consonant) {
		change = i.second;
		break;
	}
	for (auto i : vowel) {
		cons_to_vowel += i.first;
	}
	for (auto i : consonant) {
		if (i.second != change) {
			cons_to_vowel += (i.first * 2);
		}
	}

	ll final_ans = min(vowel_to_cons, cons_to_vowel);

	cout << "Case #" << cn << ":" << " " << final_ans << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("devang.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

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