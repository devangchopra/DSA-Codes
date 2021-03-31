#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;
		
	node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

node* input()
{
	int data;
	cin>>data;

	node* head=NULL;
	node* tail=NULL;

	while(data!=-1)
	{
		node* n =new node(data);
		if(head==NULL)
		{
			head=n;
			tail=n;
		}
		else
		{
			tail->next=n;
			tail=n;
		}


		cin>>data;
	}
	return head;
}




node* insert(node* head , int i ,int data)
{
	// create a new node for the incoming data
	node* n=new node(data);
	//find the address of i-1 node because we have to
	//insert the new node between i-1 and i position

	int count =0;

	node* temp= head;
	//temp variable to find position

	// handling i=0 case

	if(i==0)
	{
		n->next=head;
		head=n;
	}
	else
	{
		while(temp!=NULL and count<i-1)
		{
			temp=temp->next;
			count++;
		}
		if(temp!=NULL)
		{
			//now connect and join
			n->next=temp->next;
			//address nodal temp ke object ka next
			temp->next=n;
		}
	}

	return head;
}

void print(node* head)
{
	node* temp= head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	node* head;
	head=input();
	head=insert(head,3,100);
	print(head);
	return 0;
}