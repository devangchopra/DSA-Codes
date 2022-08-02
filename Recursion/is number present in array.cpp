#include <iostream>
using namespace std;
bool ispresent(int arr[],int n,int k)
{
	//Base Case
	if(n==0)
		return false;

	if(arr[0]==k)
		return true;

	bool isinsmall=ispresent(arr+1,n-1,k);

	return isinsmall;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int k;	
	cin>>k;
	cout<<ispresent(arr,n,k);
}