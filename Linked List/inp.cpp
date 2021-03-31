#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	//node type pointer .... isme nodal addresses aa skte hai
	// yeh sirf ek pointer hai...node nahi

	node(int data)
	{
		this->data=data;
		//this is used to specify the contents of the class i.e memebers
		next=NULL;
	}
};
node* takeinput()
{
	int data;
	cin>>data;

	node* head=NULL;
	node* tail=NULL;

	//head is start ,,, tail is end

	while(data!=-1)
	{
		node* n = new node(data);  //dma
		if(head==NULL)
		{
			head=n;
			tail=n;
			//so that head now points to the first node
		}
		else
		{
			tail->next=n;
			//connecting the two nodes
			tail=n;
			//updating tail and tail now points to the last
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
		// if i  use temp->next above then it will give me one less node
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	node* head=takeinput();  //scope of earlier head is limited
	print(head);
}