#include <iostream>
#include <string>
using namespace std;

void printsubsequences(string s,string output)
{
	if(s.size()==0)
	{
		cout<<output<<endl;
		return;
	}
	printsubsequences(s.substr(1),output+s[0]);//Include kia
	printsubsequences(s.substr(1),output);//Nhi kia

}

int main()
{
	string s="abc";
	string output="";
	printsubsequences(s,output);
}

