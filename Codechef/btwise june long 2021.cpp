#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll md=1000000007;

ll fxn(ll num1, ll num2)
{
	if(num2==0)
	{
		return 1;
	}
	if(num2==1)
	{
		return num1;
	}

	if(num2%2==0)
	{
		ll nums3=num2/2;
		ll in_x_ans=fxn(num1,nums3);

		ll temp=in_x_ans*in_x_ans;

		return temp%md;
	}
	else
	{
		ll num4=(num2-1)/2;

		ll in_y_ans=fxn(num1,num4);

		return ((num1*in_y_ans)%md*in_y_ans)%md;
	}

}

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll a,b;
		cin>>a>>b;

		ll x;

		x=fxn(2,a)+2;
		x=x-3;

		cout<<fxn(x,b)<<endl;
	}
	return 0;
}