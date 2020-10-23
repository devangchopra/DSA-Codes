//Wap to find length of string using contructor
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class string_length
{
public:
	int size=0;
	string_length(char arr[])
	{
		for(int i=0;arr[i]!='\0';i++)
		{
			size++;
		}

	}
	void output()
	{
		cout<<"Size is"<<" "<<size;
	}
};
int main()
{
	cout<<"Enter String";
	char arr[100];
	gets(arr);
	string_length obj(arr);
	obj.output();
}