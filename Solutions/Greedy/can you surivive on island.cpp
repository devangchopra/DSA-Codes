#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s,n,m;
	cin>>s>>n>>m;
	if(m>n)
	{
		cout<<-1<<endl;
	}
	if(s>6 and (n*6)<(m*7))
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<s*m<<" "<<endl;
		cout<<ceil((1.0*(s*m))/n)<<endl;

	}
}