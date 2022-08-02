#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isNumber(string s)
{
    for (ll i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}

ll ans(ll i,ll g)
{
	//i-->a
	//g-->sum-->c
	//d=1
	g=g*2;
	i=2*i;
	i--;
	//a=1
	//b=i;
	//c=-g;
	ll x=-g;
	//a=1 , b=i ,c=x
	ll a=1;
	ll b=i;
	ll c=x;
	if(b*b-4*a*c<0)
	{
		return 0;
	}
	
	else
	{
		ll m=0;
		auto x=(-b+(b*b-4*a*c))/(2*a);
		auto y=(-b-(b*b-4*a*c))/(2*a);
		cout<<endl;
		cout<<"This is Value of x"<<" "<<x;
		cout<<endl;
		cout<<"This is Value of y"<<" "<<y;
		cout<<endl;
		string strx=to_string(x);
		string stry=to_string(y);
		if(isNumber(strx)==true)
		{
			cout<<"This says x is number"<<endl;
			m++;
		}
		else if(isNumber(stry)==true)
		{
			cout<<"This says y is number"<<endl;
			m++;
		}
		return m;
		
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll T; //For Google Kickstart
	T=n; //For Google Kickstart	
	while(n--)
	{
		ll count=0;
		ll g;
		cin>>g;
		for(ll i=0;i<=g;i++)
		{
			ans(i,g);

		}
		cout<<count<<endl;
	}

	return 0;
}