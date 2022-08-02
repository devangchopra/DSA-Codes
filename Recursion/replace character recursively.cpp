#include <iostream>
using namespace std;
void replcae(char arr[],char c1,char c2)
{
	if(arr[0]=='\0')
		return;
	if(arr[0]!=c1)
	{
		replcae(arr+1,c1,c2);
	}
	else
	{
		//C1->c2
		arr[0]=c2;
		replcae(arr+1,c1,c2);
	}
}

int main()
{
	char s[100];
	cin >> s;
	char c1,c2;
	cin>>c1>>c2;
	cout<<"This is Original String"<<endl;
	cout<<s<<endl;
	replcae(s,c1,c2);
	cout<<"This is Final String"<<endl;
	cout<<s<<endl;
}