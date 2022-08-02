#include <iostream>
using namespace std;
void removeduplicates(char arr[],int size)
{
	if(arr[0]=='\0')
		return;
	if(size==1)
		return;
	if(arr[0]==arr[1])
	{
		int i=0;
		for(;i<size-1;i++)
		{
			arr[i]=arr[i+1];
		}
		arr[i]=arr[i+1];
		removeduplicates(arr,size);
	}
	else
	{
		removeduplicates(arr+1,size);
	}
}

int main()
{
	char s[1000];
	cin >> s;
	int size;
	cin>>size;
	cout<<"This is Original String"<<endl;
	cout<<s<<endl;
	removeduplicates(s,size);
	cout<<"This is Final String"<<endl;
	cout<<s<<endl;
}