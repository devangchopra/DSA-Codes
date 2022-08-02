#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,xr,yr,d;
		cin>>x>>y>>xr>>yr>>d;
		float m=x/xr;
		//cout<<m<<endl;
		float n=y/yr;
		//cout<<n<<endl;
		float ans= min(m,n);
		//cout<<ans;
		if(ans>=d)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
}