#include <bits/stdc++.h>
using namespace std;

void maxProductSubset(int arr[], int n)
{
	int zero_count=0;
	int product=1;
	int negative_int_count=0;
	int maximum_negative_number=INT_MIN;

	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			zero_count++;
			continue;
		}
		else if(arr[i]<0)
		{
			negative_int_count++;
			maximum_negative_number=max(maximum_negative_number,arr[i]);

		}
		product=product*arr[i];
	}

	if(zero_count==n)
	{
		cout<<0;
		return;
	}

	else if(negative_int_count==1 and zero_count+negative_int_count==n)
	{
		cout<<0;
		return;
	}
	else if(negative_int_count%2!=0)
	{
		product=product/maximum_negative_number;
	}

	cout<<product;
	return;
}

// Driver Code
int main()
{
	int a[] = {0,0,0,0,0,0,0,0,0,0};
	int n = sizeof(a) / sizeof(a[0]);
	maxProductSubset(a, n);
	return 0;
}


