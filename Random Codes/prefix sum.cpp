#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int prefixsum=arr[0];
	int sum=0;
	for(int i=1;i<n;i++)
	{
		prefixsum=prefixsum+arr[i];
		sum=sum+prefixsum;
	}
	cout<<sum;
}