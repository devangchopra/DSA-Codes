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
		node* n=new node(data);
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

void print(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}


node* deletea(node* head ,int i)  // not including i=0 just for the sake of clarity
{
	//finding address of i-1 node
	node* temp=head;
	int count =0;
	while(temp!=NULL and count<i-1) //handling the out of limit case also 
	{
		temp=temp->next;
		count++;
	}
	//now we got the address of i-1
	//now we want it to point to i+1
	node* a = temp->next;
	// a is the i
	node* b=a->next;
	temp->next=b;
	// connected
	delete a;
	// deallocate dynamic memory
	return head;
}


node* deletea(node* head ,int i)  // handling  i=0 case here
{
	if(i==0)
	{
		node* a;
		a=head;
		delete head;
		node* head =a;

	}
	else
	{
		//finding address of i-1 node
		node* temp=head;
		int count =0;
		while(temp!=NULL and count<i-1) //handling the out of limit case also 
		{
			temp=temp->next;
			count++;
		}
		//now we got the address of i-1
		//now we want it to point to i+1
		node* a = temp->next;
		// a is the i
		node* b=a->next;
		temp->next=b;
		// connected
		delete a;
		// deallocate dynamic memory
	}
	return head;
}







int main()
{
	node* head=input();
	print(head);
	head=deletea(head,5);
	cout<<endl;
	print(head);
	return 0;
}























