#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// 1-2 SEC 10 ^7 
//INT LIMIT 10^9

//PRIME NUMBERS USING SEIVE OF ERATOSTHENES
	/*ll x;
	cin>>x;
	std::vector<bool> isthisprime(x+1,true);
	isthisprime[0]=false;
	isthisprime[1]=false;
	for(int i=2;i<=x;i++)
	{
		if(isthisprime[i]==true)
		{
			for(int j=i*2;j<=x;j+=i)
			{
				isthisprime[j]=false;
			}
		}
	}
	int y;
	cin>>y;
	cout<<isthisprime[y];*/



//GCD AND LCM
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
	//ll T; For Google Kickstart
	//T=n; For Google Kickstart
	cin>>n;
	while(n--)
	{
		ll a,b;
		cin>>a>>b;
		ll g = gcd(a,b);
		ll m = (a*b)/g;
		cout<<g<<" "<<m<<endl;

	}
	return 0;
}