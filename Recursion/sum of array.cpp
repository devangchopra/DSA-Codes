#include <iostream>
using namespace std;
int sum(int arr[],int n)
{
	//Base Case
	if(n==0){
		return 0;
	}

	//Assumption
	int smalloutput=sum(arr+1,n-1);

	//IS
	return arr[0]+smalloutput;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<sum(arr,n);
}