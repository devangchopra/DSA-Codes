// this is implementation of circular queue
// in this representation we have to maintain front ,size varaiables
// rear is (front + size - 1)%capacity
#include<bits/stdc++.h>
using namespace std;
class circularqueue
{
public:
	long long int* arr;
	long long int size , front ,  capacity;
public:
	circularqueue(long long int c)
	{
		capacity=c;
		arr = new long long int [c];
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

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int t;
	cin>>t;
	long long int T =t+1;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int x;
		cin>>x;
		circularqueue q(n);
		circularqueue f(n);
		for (int i=0 ; i<n ;i++)
		{
			int x;
			cin>>x;
			q.enqueue(x);
		}		
		while(q.isempty()==false)
		{
			int x =0;
			if (q.arr[0]<=x)
			{
				q.dequeue();
				f.enqueue(x+1);
				x++;
			}
			else
			{
				q.enqueue(q.arr[0]-x);
				q.dequeue();
				x++;
			}
		}
		for (int i=0;i<n;i++)
		{
			cout<<f.arr[i]<<" ";
		}

	}
	
}