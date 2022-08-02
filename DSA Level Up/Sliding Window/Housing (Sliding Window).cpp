#include <bits/stdc++.h>
using namespace std;

void housing(int* arr,int n,int k)
{
	int i= 0;
	int j= 0;
	int cs= 0;

	while(j<n)
	{
		//Expand
		cs+=arr[j];
		j++;

		//Removal if cs>k
		while(cs>k and i<j)
		{
			//So that atleast one element remains
			cs = cs-arr[i];
			i++;
		}

		//Check point
		if(cs==k)
		{
			cout<<i<<" "<<j-1<<endl;
		}
	}
	//return; 
}

int main()
{
	int arr[] = {1 ,3 ,2 ,1 ,4 ,1 ,3 ,2 ,1 ,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 8;
	housing(arr,n,k);
	return 0;
}