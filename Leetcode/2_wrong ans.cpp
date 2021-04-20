#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string sentence1;
	getline (cin, sentence1);

	
	string sentence2;
	getline (cin, sentence2);
	
	
	int s1=0;
	int s2=0;
	
	for(int i=0;i<sentence1.length();i++)
	{
		if(sentence1[i]==' ')
		{
			break;
		}
		else
		{
			s1++;
		}
	}
	for(int i=0;i<sentence2.length();i++)
	{
		if(sentence2[i]==' ')
		{
			break;
		}
		else
		{
			s2++;
		}
	}
	int x=0;
	for(int i=0;i<s1;i++)
	{
		if(sentence1[i]!=sentence2[i])
		{
			x=1;
			break;
		}
	}
	if(x==0)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
	
}