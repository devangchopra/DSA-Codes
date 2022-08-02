#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x,d;
		cin>>n>>x>>d;

		bool flag=false;

		//forward abs(x-0)/d+1
		int ans=(abs(x-0)/d)+1;
		double ans1=(abs(double(x-0)/d))+1;

		if(abs(ans1-ans)==0)
		{
			flag=true;
		}
		else
		{
			ans=(abs(x-(n+1))/d)+1;
			ans1=(abs(double(x-(n+1)))/d)+1;

			if(abs(ans1-ans==0))
			{
				flag=true;
			}

		}


		if(flag==true)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}


		
	}
}