#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int data)
	{
		this->data = data;
		next=NULL;
	}

};

node* takeinput() // coz return type is head (int -int)
{
	int data;
	cin>>data;
	node* head=NULL;
	while(data!=-1)
	{
		node* n = new node(data);   //dynamic memory will not go untill we get rid of it
		if (head==NULL)
		{
			head=n;//both n and head are nodal type address
		}
		else
		{
			// if we are not in the first position then traverse
			node* temp = head ; // never loose head
			while(temp->next!=NULL)
			{
				temp=temp->next; // association happens from right to left 
				  				 // we are reaching the end
			}
			temp->next=n; //address of new node
		}

		cin>>data;
	}
	return head;
}

void print(node* head)
{
	node* temp = head;
	while(temp!=NULL) // temp ke andr addrss hai
	{
		cout<<temp->data<<" ";  // jis address ko wo point kr rha hai uska data .*
		temp=temp->next;
	}
}

int main()
{
	node * head;
	head=takeinput();
	print(head);
}