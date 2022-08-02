#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
	int n=1001;

	string s=to_string(n);

	int size=int(log10(n))+1;

	int count=1;

	for(int i=0;i<size-1;i++)
	{

		int x=s[i]-'0';
		x=x*10;
		if(x>=26) continue;
		if(x==0) continue;
		x=x+(s[i+1]-'0');
		if(x<=26)
		{
			count++;
		}

	}
	cout<<count<<endl;
}