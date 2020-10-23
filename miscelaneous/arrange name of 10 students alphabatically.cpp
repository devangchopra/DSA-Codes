// Wap to arrange names of 10 students alphabatically

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
class record
{
public:
	char name[50];

};
int main()
{
	record obj[10];
	record temp;
	for(int i=0;i<10;i++)
	{
		cin>>obj[i].name;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(strcmp(obj[i].name,obj[j].name)>0)
			{
				temp=obj[i];
				obj[i]=obj[j];
				obj[j]=temp;
			}
		}
	}
	cout<<"Sorted Are"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<obj[i].name<<endl;
	}
}