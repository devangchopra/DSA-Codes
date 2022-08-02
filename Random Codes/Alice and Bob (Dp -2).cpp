#include <bits/stdc++.h>
using namespace std;

const int n = 3e5;
int dp[n+1];

int main()
{
	int n;
	cin>>n;

	dp[0]=0;
	dp[1]=0;

	for(int i=2;i<=n;i++)
	{
		dp[i]=1;
		//initialyy we take ki chalo winning hai

		if(i-2>=0)
		{
			dp[i]=dp[i] and dp[i-2];
		}

		if(i-10>=0)
		{
			dp[i]=dp[i] and dp[i-10];
		}

		if(i-50>=0)
		{
			dp[i]=dp[i] and dp[i-50];
		}

		if(i-100>=0)
		{
			dp[i]=dp[i] and dp[i-100];
		}

		dp[i]=!dp[i]; 
	}
	cout<<dp[n]<<endl;
}

