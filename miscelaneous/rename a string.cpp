// wap to reverse a string without using any string function
#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter String to be reversed";
	string str;
	getline(cin,str);

	char arr[str.length()];

	int x =0;

	for(int i=str.length()-1;i>=0;i--)
	{
		arr[x]=str[i];
		x++;
	}
	for(int i=0;i<str.length() ;i++)
	{
		cout<<arr[i];
	}
	return 0;
}