//Wap to find the frequency or occurance of a word in a given string without using any of string function  
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
	string str;
	cout<<"Enter String";
	getline(cin,str);
	char arr[str.length()];
	for (int i=0;i<str.length();i++)
	{
		arr[i]=0;
	}
	cout<<"Frequencies are as follows"<<endl;
	for (int i=0;i<str.length();i++)
	{
		int count =1;
		for (int j=i+1;j<str.length();j++)
		{
			if (str[i]==str[j])
			{
				count++;
				arr[j]=-1;
			}
		}
		if(arr[i]!=-1)
		{
			cout<<str[i]<<" "<<"->"<<" "<<count<<endl;
			arr[i]=-1;
		}
	}
}