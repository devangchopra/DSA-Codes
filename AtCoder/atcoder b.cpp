#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fun()
{
	int n;
	cin >> n;
	int temp = n;
	set<pair<string, string>>m;

	pair<string,string>p;
	while (n--)
	{
		string s, t;
		cin >> s >> t;
		p={s,t};
		m.insert(p);
	}
	if(m.size()<temp)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fun();
	return 0;
}


