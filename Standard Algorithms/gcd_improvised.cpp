#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
{
	if(b==0)
        return a;

    else return gcd(b,a%b);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	while(n--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;
		
	}
	return 0;
}