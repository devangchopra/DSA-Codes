#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n;
	cin>>n;
	long long int arr[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	for (int i=0;i<n;i++)
		cout<<arr[i]*arr[i]<<endl;
}