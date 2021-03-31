#include<bits/stdc++.h>
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
	}
	return head;
}


node* merge(node* h1,node* h2)
{
	node* fh=NULL;
	node* ft=NULL;

	if (h1->data > h2->data)
	{
		fh=h2;
		ft=h2;
		h2=h2->next;

	}

	else
	{
		fh=h1;
		ft=h1;
		h1=h1->next;
	}

	while(ft!=NULL)
	{
		if(h1==NULL)
		{
			ft->next=h2;
			ft=h2;
			h2=h2->next;
		
		}
		else if(h2==NULL)
		{
			ft->next=h1;
			ft=h1;
			h1=h1->next;
			
		}
		else
		{
			if(h1->data > h2->data)
			{
				ft->next=h2;
				ft=h2;
				h2=h2->next;
			}
			else
			{
				ft->next=h1;
				ft=h1;
				h1=h1->next;
			}
		}
	}
	return fh;
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

int main()
{
	node* head_1=input();
	print(head_1);
	node* head_2=input();
	print(head_2);
	node* fh=merge(head_1,head_2);
	print(fh);
}

