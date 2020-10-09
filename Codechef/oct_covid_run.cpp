#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll ntc;
	cin>>ntc;
	while(ntc--)
	{
		ll N,K,X,Y;
		cin>>N>>K>>X>>Y;
		ll flag=0;
		ll OX = X;
		X=(X+K)%N;

		while(true)
		{
			//cout<<X<<" ";
			if(X==Y)
			{

				flag =1;
				break;

			}
			if(X==OX)
			{
				flag=0;
				break;
			}
			
			X=(X+K)%N;

		}
		if(flag==1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}