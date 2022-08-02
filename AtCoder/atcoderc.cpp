#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fun()
{
	ll n;
	cin>>n;

	string final;
	final.push_back('A');

	if(n==1){
		cout<<final<<endl;
		return;
	}

	ll ans = 1;

	while(ans!=n)
	{	
		if(ans*2<n){
			final.push_back('B');
			ans=ans*2;
		}
		else{
			final.push_back('A');
			ans=ans+1;
		}
	}
	cout<<final<<endl;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fun();
	return 0;
}


