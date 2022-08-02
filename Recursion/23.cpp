#include<bits/stdc++.h>
using namespace std;
#define ll long long int
float rounda(float var)
{
	
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;
	while(t--)
	{
		float k1,k2,k3,v;
		cin>>k1>>k2>>k3>>v;
		float ans = k1*k2*k3*v;
  		float f_ans=100/ans;
  		float f=rounda(f_ans);

  		if(f < 9.58)
  		{
  			cout<<"YES"<<endl;
  		}
  		else
  		{
  			cout<<"NO"<<endl;
  		}



	}
}