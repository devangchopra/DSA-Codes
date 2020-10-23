// Wap to find all the characters from the strings which appeared once
#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter String";
	string str;
	getline(cin, str);
	for(int i=0; i< str.length();i++)
	{
		int x =1;

		for (int j=i+1;j<str.length();j++)
		{
			if(str[i]==str[j])
			{
				x=0;
				break;
			}
		}
		if (x==1)
			cout<<str[i]<<" ";

	}
}