#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[n];
	int brr[n];

	for(int i=0;i<n;i++) cin>>arr[i];

	for(int i=0;i<n;i++) cin>>brr[i];

	sort(arr,arr+n);
	sort(brr,brr+n);

	int ans=0;

	for(int i=0;i<n;i++)
	{
		ans=ans+abs(arr[i]-brr[i]);
	}

	cout<<ans;

}