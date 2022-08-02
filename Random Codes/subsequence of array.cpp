#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;	
	int arr[m];
	for (int i = 0; i < m; ++i) cin>>arr[i];

	int n;
	cin>>n;
	int subsequence[n];
	for (int i = 0; i < n; ++i) cin>>subsequence[i];

	int x=0;
	

	for(int i=0;i<m;i++)
	{
		if(subsequence[x]==arr[i])
		{
			x++;
		}
	}
	if(x<=m)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}