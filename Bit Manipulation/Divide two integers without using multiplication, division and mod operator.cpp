#include <bits/stdc++.h>
using namespace std;

//Prone To TLE
int main()
{
	int n;
	cin>>n;

	int m;
	cin>>m;

	int counter=0;

	int n1=abs(n);
	int n2=abs(m);

	while(n1>=n2)
	{
		n1=n1-n2;
		counter++;
	}

	
	if(n<0 or m<0)
	{
		cout<<counter-(2*counter)<<endl;
	}

	else
	{
		cout<<counter<<endl;
	}

	
}