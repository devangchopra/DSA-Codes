#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin>>n;
	int k;
	k=n;
	int f,l;
	f=n;
	l=n;
	while(f--)
	{
		cout<<"#";
	}
	cout<<"\n";

	k=k-2;
	while(k--)
	{
		cout<<"*";
		for(int i=0;i<n-2;i++)
			cout<<" ";
		cout<<"*";
		cout<<"\n";
	}	
		
	while(l--)
	{
			cout<<"#";
	}
		
}