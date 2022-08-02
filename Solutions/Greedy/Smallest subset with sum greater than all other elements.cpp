#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={2, 1, 2};
	int n=sizeof(arr)/sizeof(arr[0]);

	sort(arr,arr+n);

	int sum=0;

	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}



	int subset_size=0;
	int temp_sum=arr[n-1];
	sum=sum-arr[n-1];

	for(int i=n-1;i>=0;i--)
	{
		subset_size++;
		if(temp_sum>sum)
		{
			break;
		}
		else
		{
			temp_sum+=arr[i];
			sum-=arr[i];
		}
	}

	cout<<subset_size<<endl;

	return 0;
}