#include<bits/stdc++.h>
using namespace std;
prime (int n )
{
	int m =0;
	for(int i =2;i<n/2+1;i++)
	{
		if (n%i==0)
		{
			m=1;
			break;
		}

	}
	return m;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	long long int n;
	cin>>n;
	int x = 0;
	for (int i =2; x!=n ; i++)
	{
		if (prime(i) == 0)
		{
			cout<<i<<endl;
			x++;
		}

	}

}