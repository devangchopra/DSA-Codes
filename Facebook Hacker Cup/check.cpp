#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fun(ll cn)
{
	string s;
	cin >> s;

	unordered_set<char> temp;
	map<char, int> mp;

	ll vc = 0;
	ll cc = 0;

	for (auto i : s)
	{
		if (i == 'A' or i == 'E' or i == 'I' or i == 'U' or i == 'O')
		{
			vc++;
			mp[i]++;
		}
		else
		{
			cc++;
			mp[i]++;
		}
		temp.insert(i);
	}

	multimap<int, char, greater<int>> VowelMap;
	multimap<int, char, greater<int>> ConsonantMap;

	for (auto i : mp)
	{
		char c = i.first;
		if (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
		{
			VowelMap.insert({i.second, i.first});
			continue;
		}
		ConsonantMap.insert({i.second, i.first});
	}

	
	if (temp.size() == 1)
	{
		cout << "Case #" << cn << ":" << " " << 0 << endl;
		return;
	}

	

	char change ='\0';

	cout<<VowelMap.size()<<" "<<ConsonantMap.size()<<endl;






/*	if (VowelMap.size() < ConsonantMap.size())
	{

		ll ans = 0;

		for (auto i : ConsonantMap)
		{
			ans += i.first;
		}

		for (auto j : VowelMap)
		{
			change = j.second;
			break;
		}


		for (auto j : VowelMap)
		{
			if (j.second != change)
			{
				ans += (j.first * 2);
			}
		}

		cout << "Case #" << cn << ":" << " " << ans << endl;
		return;
	}

	else
	{

		ll ans = 0;

		for (auto i : VowelMap)
		{
			ans += i.first;
		}

		for (auto j : ConsonantMap)
		{
			change = j.second;
			break;
		}

		for (auto j : ConsonantMap)
		{
			if (j.second != change)
			{
				ans += (j.second * 2);
			}
		}

		cout << "Case #" << cn << ":" << " " << ans << endl;
		return;
	}*/

	return;


}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

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


//consistency_chapter_1_validation_