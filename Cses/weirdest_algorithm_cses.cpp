#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	cout<<n<<" ";
	for (int i =0 ; n!=1 ; i++)
	{
		if (n%2==0)
		{
			n=n/2;			
		}
		else 
		{
			n=n*3;
			n++;
			
		}
		cout<<n<<" ";
	}
}