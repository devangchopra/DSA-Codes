#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,c;
	cin>>a>>b>>c;
	if(a==b)
		cout<<c;
	else if(b==c)
		cout<<a;
	else if(a==c)
		cout<<b;
	else
		cout<<0;
	return 0;
}