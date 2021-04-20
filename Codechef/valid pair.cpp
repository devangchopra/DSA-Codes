#include<iostream>
using namespace std;
int main()
{
	int arr[3];
	for(int i=0;i<3;i++)
	{
		cin>>arr[i];
	}
	int x= arr[0];
	bool flag=false;
	for(int i=1;i<3;i++)
	{
		if(arr[i]==x)
		{
			flag=true;
			break;
		}
	}
	if(flag==true)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}