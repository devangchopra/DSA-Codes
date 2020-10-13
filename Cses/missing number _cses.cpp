#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n;
	cin>>n;
 
	long long int arr[n-1];
	for (int i=0;i<n-1;i++)
		cin>>arr[i];
 
	sort(arr,arr+(n-1));
 
	if (arr[0]==2)
		cout<<1;
	else
	{
		for (int i=0;i<(n-1);i++)
		{
			if (arr[i+1]-arr[i]!=1)
			{
				cout<<arr[i]+1;
				break;
			}
		}
	}
 
}