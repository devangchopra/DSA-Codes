/*
This question is asked by Google. 
Given a string, return whether or not it uses capitalization correctly. 
A string correctly uses capitalization if all letters are capitalized, 
no letters are capitalized, or only the first letter is capitalized.
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	if(s.size()<=1)
	{
		cout<<true<<endl;
	}
	else
	{
		if(s[0]>=65 and s[0]<=90)
		{
			if(s[1]>=65 and s[1]<=90)
			{
				bool x=true;
				for(int i=2;i<s.size();i++)
				{

					if(s[i]>=65 and s[i]<=90)
					{

					}
					else
					{
						x=false;
						break;
					}
				}
				cout<<x<<endl;
			}
			else
			{
				bool x=true;
				for(int i=1;i<s.size();i++)
				{

					if(s[i]>=97 and s[i]<=122)
					{

					}
					else
					{

						x=false;
						break;
					}
				}
				cout<<x<<endl;
			}
		}
		else
		{
			bool x=true;
				for(int i=1;i<s.size();i++)
				{


					if(s[i]>=97 and s[i]<=122)
					{

					}
					else
					{

						x=false;
						break;
					}
				}
				cout<<x<<endl;
		}
	}
	return 0;
}