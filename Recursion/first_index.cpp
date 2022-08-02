#include<bits/stdc++.h>
using namespace std;
int ans(int arr[],int size, int x)
{
	if(size<1)
	{
		return -1;
	}
	else if(arr[0]==x)
	{
		return 0;
	}
	else
	{
		int i=ans(arr+1,size-1,x);
		return i==-1 ? i:i+1;
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
	cout<<ans(arr,n,k);
}