#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#include<stdio.h>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll ntc;
	cin>>ntc;
	while(ntc--)
	{
		ll n;
		cin>>n;
		if(n%2){printf("%lld\n",(n/2)+1);}
    	else{printf("%lld\n",n/2);}
	}
	return 0;
}