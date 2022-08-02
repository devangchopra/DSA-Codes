#include <iostream>
using namespace std;

class CircularQueue
{
	int* arr;
	int  size;
	int  front;
	int  capacity;

public:
	CircularQueue(int c)
	{
		capacity=c;
		arr = new int [c];
		front = 0;
		size = 0;
	}

	bool isfull()
	{
		if(capacity==size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty()
	{
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getFront()
	{
		if(isEmpty()==true)
		{
			return -1;
		}
		else
		{
			return front;
		}
	}

	int getRear()
	{
		if(isEmpty()==true)
		{
			return -1;
		}
		else
		{
			return (front+size-1)%capacity;
		}
	}

	void enqueue(int x)
	{
		if(isfull()==true)
			return;
		else
		{
			int rear=getRear();
			rear=(rear+1)%capacity;
			arr[rear]=x;
			size++;
		}
	}

	void dequeue()
	{
		if(isEmpty()==true)
		{
			return;
		}
		else
		{
			front=(front+1)%capacity;
			size--;
		}
	}
};

