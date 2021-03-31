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
node* takeinput()
{
	int data;
	cin>>data;

	node* head=NULL;
	node* tail=NULL;
	while(data!=-1)
	{
		node* n = new node(data); 
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
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
node* reverse(node* head)
{
	//In this we will use recursion
	//Recursion has 3 stepe : Base,Call,Small / Base,Small,Case

	//base case
	if(head==NULL || head->next==NULL) //either no or only one node
	{
		return head;
	}
	else
	{
		node* smallans=reverse(head->next);
		//calling small (n-1) and assuming that after calling the list is sorted
		node* temp=smallans;
		//storing head of (n-1) sorted in temp so that i can traverse and get the last node
		while(temp->next!=NULL)
		{
			temp=temp->next;
			//stopping at the last
		}
		temp->next=head; // conneting the last node to the head
		head->next=NULL; //clear the head
	
	    return smallans; // retruning the new head
    }
}
int main()
{
	node* head=takeinput();
	print(head);
	cout<<"Reversed : "<<endl;
	node* head_2=reverse(head);
	print(head_2);
}