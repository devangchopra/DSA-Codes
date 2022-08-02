//Implementing stack from scratch 
//All operartions are O(1)\
//Minimal things used
#include <iostream>
#define endl "\n"
using namespace std;

class stack
{
	int size;
	int* arr;
	int currsize=-1;
public:
	stack(int n)
	{
		this->size=n;
		arr= new int[n];
	}

	void push(int n)
	{
		if(currsize==size-1)
		{
			//Indexinhg : 0->n-1
			cout<<"Overflow"<<endl;
			return;
		}
		currsize++;
		arr[currsize]=n;
	}

	int top()
	{
		return arr[currsize];
	}

	void pop()
	{
		if(currsize==-1)
		{
			cout<<"Underflow"<<endl;
			return;
		}
		currsize--;
	}
	
	bool isEmpty()
	{
		if(currsize==-1)
		{
			return true;
		}
		else
			return false;
	}
};

int main()
{
	stack s(10);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	s.push(80);
	s.push(90);
	s.push(100);
	cout<<s.top()<<endl;

	s.pop();
	s.pop();
	s.pop();
	s.pop();
	//Expected o/p : 60
	cout<<s.top()<<endl;
	cout<<"Empty Property"<<s.isEmpty()<<endl;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	// I should get underflow 2 times.
	s.pop();
	s.pop();
	s.pop();

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	s.push(80);
	s.push(90);
	s.push(100);

	cout<<"Now Top"<<" "<<s.top()<<endl;

	s.push(120);
	//I should get overflow
}