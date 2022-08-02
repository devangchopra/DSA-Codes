#include <iostream>
using namespace std;
void fxn(int arr[],int size)
{
	if(size==0)
		return;
	fxn(arr+1,size-1);
	cout<<arr[0];
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i= 0;i<n;i++)
	{
		cin>>arr[i];
	}
	fxn(arr,n);
}