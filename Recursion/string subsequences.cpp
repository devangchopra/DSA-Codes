#include <iostream>
using namespace std;
int subs(string s,string output[])
{
	//Base Case
	if(s.size()==0)
	{
		output[0]=" ";
		return 1;
	}
	string smallstrings=s.substr(1);
	int smallstringsize=subs(smallstrings,output);

	//Copy 
	for(int i=0;i<smallstringsize;i++)
	{
		output[i+smallstringsize]=s[0]+output[i];
	}
	return 2*smallstringsize;
}
int main()
{
	string s;
	cin>>s;
	//Sequence : 2^n
	string * output= new string[1000];
	//Size...kitna bhra hai
	int count=subs(s,output);
	for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}