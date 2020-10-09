// Basically we are maintaining a size element to track in array with front being as first and rear being as last
#include<iostream>
using namespace std;
class queue
{
private:
	int size , capacity;
	int* arr; // pointer pointing to dynamic array 
public:
	queue(int c)
	{
		this->capacity=c;
		size=0;
		arr= new int [capacity]; // dynamically allocated array in pool with no name		
	}
	bool isfull()
	{
		if (capacity==size)
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
		if (isempty()==true)
			return -1 ;
		else
			return 0 ; // coz in array representation we always consider front as 0
	}
	int getrear()
	{
		if (isempty()==true)
			return - 1 ; // always make this as habbit to use rt -1 when false
		else
			return size-1 ; // coz in array representation we always consider back as the last  
	}
	void enqueue(int x)
	{
		if (isfull()==true)
			return ; //bahar aa jao
		else
		{
			arr[size]=x;
			size++;
		}	

	}
	void dequeue()
	{
		if (isempty()==true)
			return;
		else
			for (int i =0 ; i<size-1;i++) //bcoz FIFO
				arr[i]=arr[i+1];
			size--;
	}

};
int main()
{
	queue obj (10);  //parameterized constructor 
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