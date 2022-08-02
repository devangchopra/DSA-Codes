#include <iostream>
#include <stack>

using namespace std;

//Functions -> create

void insert(stack<int> &s,int ele)
{
	if(s.size()==0)
	{
		s.push(ele);
		return;
	}

	int temp=s.top();
	s.pop();
	insert(s,ele);
	s.push(temp);
	return;
}
void reverse(stack <int> &s)
{
	//Base case
	if(s.size()==1)
		return;

	int temp=s.top();
	s.pop();
	reverse(s);


	//Insertion Step
	insert(s,temp);

	return;
}

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	reverse(s);

	while(s.empty()==false)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}