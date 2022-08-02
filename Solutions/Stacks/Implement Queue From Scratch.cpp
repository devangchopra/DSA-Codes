#include <iostream>
using namespace std;

class queue
{
	int* arr;
	int  front;
	int  rear;
	int  size;

public:
	queue(int n)
	{
		arr=new int[n];
		front=0;
		rear=-1;
		size=n;
	}

	void enqueue(int x)
	{
		if(rear<size)
		{
			rear++;
			arr[rear]=x;
		}
		else
		{
			cout<<"Overflow"<<" ";
		}
	}

	int deque()
	{
		int x = arr[front];

		for(int i=0;i<size-1;i++)
		{
			arr[i]=arr[i+1];
		}
		rear--;
		return x;
	}

	bool isEmpty()
	{
		bool x =true;
		if(rear==-1)
		{
			x=false;
		}
		return x;
	}
	void print()
	{
		for(int i=0;i<size;i++)
		{
			cout<<arr[i]<<" ";
		}
	}

};

int main()
{
	queue q(10);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.enqueue(70);
	q.enqueue(80);
	q.enqueue(90);
	q.enqueue(100);

	while(q.isEmpty()!=false)
	{
		int x =q.deque();
		cout<<x<<" ";
	}

	return 0;
}