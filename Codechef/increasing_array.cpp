#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n;
	cin>>n;
	long long int arr[n];
	long long int count  = 0;
	for (int i= 0;i<n;i++)
		cin>>arr[i];
	for (int i=0;i<n-1;i++)
	{
		if (arr[i+1]<arr[i])
		{
			count+=arr[i]-arr[i+1];
			arr[i+1]=arr[i];
		}
	}
	cout<<count;
}