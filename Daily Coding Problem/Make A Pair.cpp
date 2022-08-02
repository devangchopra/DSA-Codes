#include <bits/stdc++.h>
using namespace std;

class pairs
{
public:
	int a;
	int b;

	void cons(int a,int b)
	{
		this->a=a;
		this->b=b;
	}

	int car(int a,int b)
	{
		cons(a,b);
		return this->a;
	}

	int cdr(int a,int b)
	{
		cons(a,b);
		return this->b;
	}
};
int main()
{
	pairs obj;
	cout<<obj.car(30,20)<<endl;
	cout<<obj.cdr(30,20);
}