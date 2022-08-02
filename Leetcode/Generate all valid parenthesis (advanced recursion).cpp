#include <bits/stdc++.h>
using namespace std;

//defination of our recursive call
vector<string>valid;
void generate(string &s,int open,int close)
{
	//Base Condition
	if(open==0 and close==0)
	{
		valid.push_back(s);
		return;
	}

	//Left Tree Call
	if(open>0)
	{
		s.push_back('(');
		generate(s,open-1,close);
		//complete the choosen subtree
		s.pop_back();
	}

	//Right Tree Call
	if(close>0)
	{
		//For Validation
		if(open<close)
		{
			//this means in string we have more opening brackets then the close
			s.push_back(')');
			generate(s,open,close-1);
			//complete the right subtree
			s.pop_back();
		}
	}

}