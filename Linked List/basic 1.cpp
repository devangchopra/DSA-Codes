//linked list
// dynamic array in whichh the memory locations are not continuous
// insertions and deletions are cheaper then array
/*
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* next; // node type pointer ... isme node ka address store hoga

	node(int data)
	{
		this->data=n;
		next=NULL;	
	}
}

int main()
{
	node n1(10);
	node n2(20);
	// creation of two nodes statically
	
	// now for joining the two nodes
	n1.next=&n2;

	//now making a head pointer for storing nodal adress

	node* head = &n1;

	// now for dynamic memory allocation
	node* n3= new node(10); // n3 ek pointer hai containing address
	// new se heap structure used in memory 
	node* n4 = new node(20);

	n3->next=n4;

	// .* :: -> 

	node* head = n3;

	// n3 already containing address

	cout<<head->data;
}
*/

//####################################################
//printing a linked list

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

void print(node* head)
{
	//never loose head
	//its a copy but then also save it
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	node* n1= new node(10);
	node* n2= new node(20);
	node* n3= new node(30);
	n1->next=n2;
	n2->next=n3;
	n3->next=NULL;
	node * head = &n1;
	print(head);
	return 0;
}