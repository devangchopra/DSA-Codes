// this is implementation of circular queue
// in this representation we have to maintain front ,size varaiables
// rear is (front + size - 1)%capacity
#include<iostream>
using namespace std;
class circularqueue
{
private:
	int* arr;
	int size , front ,  capacity;
public:
	circularqueue(int c)
	{
		capacity=c;
		arr = new int [c];
		front = 0;
		size = 0;
	}
	bool isfull()
	{
		if(capacity==size)
			return true;
		else
			return false;
	}
	bool isempty()
	{
		if (size==0)
			return true;
		else
			return false;
	}
	int getfront()
	{
		if(isempty()==true)
			return -1;
		else
			return front;
	}
	int getrear()
	{
		if(isempty()==true)
			return -1;
		else
			return (front+size-1)%capacity;
	}
	void enqueue(int x)
	{
		if(isfull()==true)
			return;
		else
			{
				int rear = getrear();	
				rear = (rear+1)%capacity;
				arr[rear]=x;
				size++;
			}
	}
	void dequeue()
	{
		if(isempty()==true)
			return;
		else
		{
			front=(front+1)%capacity;
			size--;
		}
	}
};

int main()
{
	circularqueue obj(10);
	cout<<endl<<obj.isfull();
	cout<<endl<<obj.isempty();
	cout<<endl<<"FRONT IS "<<obj.getfront();
	cout<<endl<<"REAR IS"<<obj.getrear();
	obj.enqueue(10);
	obj.enqueue(20);
	obj.enqueue(30);
	obj.enqueue(40);
	obj.enqueue(50);
	obj.enqueue(60);
	obj.enqueue(70);
	obj.enqueue(80);
	obj.enqueue(90);
	obj.enqueue(100);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	cout<<endl<<"FRONT IS "<<obj.getfront();
	cout<<endl<<"REAR IS"<<obj.getrear();
}