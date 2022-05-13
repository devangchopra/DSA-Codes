#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fun(ll cn)
{
	string s;
	cin >> s;

	unordered_set<char> temp;

	unordered_set<char> distintVowels;
	unordered_set<char> distintConsonants;

	ll vc = 0;
	ll cc = 0;

	for (auto i : s)
	{
		if (i == 'A' or i == 'E' or i == 'I' or i == 'U' or i=='O')
		{
			vc++;
			distintVowels.insert(i);
		}
		else
		{
			cc++;
			distintConsonants.insert(i);
		}
		temp.insert(i); //O(1)
	}

	if (temp.size() == 1)
	{
		cout << "Case #" << cn << ":" << " " << 0 << endl;
		return;
	}

	ll from_Conversion , to_Conversion;

	if (vc > cc)
	{
		from_Conversion = vc;
		to_Conversion = distintConsonants.size();
	}

	else if (cc > vc)
	{
		from_Conversion = cc;
		to_Conversion = distintVowels.size();
	}

	else
	{
		//cc=vc
		ll v1 = distintVowels.size();
		ll v2 = distintConsonants.size();

		if (v1 == v2)
		{
			from_Conversion = cc;
			to_Conversion = distintVowels.size();
		}

		else if (v1 < v2)
		{
			from_Conversion = cc;
			to_Conversion = distintVowels.size();
		}
		else
		{
			from_Conversion = vc;
			to_Conversion = distintConsonants.size();
		}
	}

	ll ans = 0;
	ans += from_Conversion;

	if(to_Conversion>1)
	{
		to_Conversion--;
		ans+=(to_Conversion*2);
	}


	cout << "Case #" << cn << ":" << " " << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
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


