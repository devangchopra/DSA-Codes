#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	cin>>n>>i;

	int x=n&(1<<i);

	if(x==0)
		cout<<n<<endl;
	else
	{
		x=(n&~(1<<i));
		cout<<x<<endl;
	}


	return 0;
}