//Linked list implementation
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node* next; //int* x --> usi trh class kya hai ...user defined data type (you know its in the form of array) ....therefore usk data type ka pointer.....yaani wo doosre node_daya_type ko point krega
};

node* start = NULL;   //start pointer taki jo heap mei memory ai hai wo de allocate na ho
node* t = NULL;       // treaversal pointer

void add(int num)
{
	if(start==NULL)
	{
		node* p = new node(); 
		//creating a pointer of node type data with dynamic memory allocation in heap with no name //
		p->data = num; //*p.:: p->
		p->next = NULL;

		// p is a pointer which can have addresses of other nodes and in this case it is pointing to new node
		start = p; // start ke andar p ka address so that dynamic memory allocated has a reference and doesnot gets deleted after function call is over
	}
	else
	{
		t = start;
		while(t->next !=NULL)
		{
			t=t->next; // t ke andar t->next yani next node pointer ka address
		}
		node* p =new node();
		p->data=num;
		p->next=NULL;

		t->next=p;  // t ke next part mein new node ka address

	}
	t=NULL; // disconnecting traversal
}
void display()
{
	t=start;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}
int main()
{
	add(100);
	add(200);
	add(300);
	add(400);
	display();
}