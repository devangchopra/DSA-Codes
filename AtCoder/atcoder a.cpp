#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fun()
{
	double c;
	cin >> c;

	float m = c - int(c);

	int y = (m*10);

	//cout<<y<<endl;

	if (y <= 2)
		cout << int(c) << "-" << endl;
	else if (y >= 3 and y <= 6)
		cout << int(c) << endl;
	else
		cout << int(c) << "+" << endl;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fun();
	return 0;
}


