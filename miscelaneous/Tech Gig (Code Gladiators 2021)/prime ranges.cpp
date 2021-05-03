#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{

		ll smll;
		ll big;
		cin>>smll>>big;

		ll x=big+1;	//big range
		

		vector<bool> isthisprime(x+1,true);
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

		bool flag=false;

		// finding smallest
		ll fsm;
		for(int i=smll; i<=big;i++)
		{
			if(isthisprime[i]==true)
			{
				fsm=i;
				flag=true;
				break;
			}
		}

		//cout<<fsm<<endl<<endl;

		//finding big
		ll fbig;
		for(int i=big;i>=smll;i--)
		{
			if(isthisprime[i]==true)
			{
				fbig=i;
				flag=true;
				break;
			}
		}

		//cout<<fbig<<endl<<endl;


		if(flag==true)
		{
			cout<<fbig-fsm<<endl;	
		}
		else
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}