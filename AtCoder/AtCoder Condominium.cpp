#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;

	
	int ans=0;
	int h=n;
	
	while(h)
	{
		ans=ans+100*h*k;
		h--;
	}

	//cout<<ans<<endl;
	//sum of numbers till k
	int c=k;
	int temp=(c*(c+1))/2;

	//cout<<temp<<endl;

	ans=ans+(temp*n);

	cout<<ans;
	return 0;
}