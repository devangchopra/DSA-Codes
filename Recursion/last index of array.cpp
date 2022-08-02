#include <bits/stdc++.h>
using namespace std;
//arr being  passed a pointer

int lastindex(int arr[],int n,int k)
{
	//Base Case
	if(n==0)
	{
		return -1;
	}
	//We have to call
	int ans=lastindex(arr+1,n-1,k);
	//Asseume yeh ans le ayega

	//Small Calcluation
	if(ans==-1)
	{
		if(arr[0]==k)
		{
				return 0;
		}
	}
	else
	{
		return ans+1;
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int k;
	cin>>k;
	cout<<lastindex(arr,n,k);

}