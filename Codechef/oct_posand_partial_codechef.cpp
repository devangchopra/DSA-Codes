#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll a;
		cin>>a;
		if(a==1)
			cout<<-1<<endl;
		else if(a==2)
			cout<<-1<<endl;
		else if(a==3)
			cout<<1<<" "<<3<<" "<<2<<endl;
		else if(a==4)
			cout<<-1<<endl;
		else if(a==5)
			cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<endl;
		else if(a==6)
			cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<" "<<6<<endl;
		else if(a==7)
			cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<" "<<6<<" "<<7<<endl;
		else if(a==8)
			cout<<-1<<endl;
		else if(a==9)
			cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<" "<<6<<" "<<7<<" "<<9<<" "<<8<<endl;
	}
}