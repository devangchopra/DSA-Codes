#include<bits/stdc++.h>
using namespace std;
class linknode
{
public:
	int data;
	linknode* next;

	linknode(int data)
	{
		this->data=data;
		next=NULL;
	}
};

class treenode
{
	public:

	int data;
	treenode* left;
	treenode* right;

	treenode(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};

treenode* takeinput()
{
	int data;
	cin>>data;
	treenode* root=new treenode(data);
	queue<treenode*>q;
	q.push(root);
	while(q.size()!=0)
	{
		treenode* temp=q.front();
		q.pop();
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			treenode* leftnode=new treenode(leftdata);
			q.push(leftnode);
			temp->left=leftnode;
		}
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			treenode* rightnode=new treenode(rightdata);
			q.push(rightnode);
			temp->right=rightnode;
		}
	}
	return root;
}

vector<linknode*> levelwiselinkedlist(treenode* root)
{
	vector<linknode*>v;
	queue<treenode*>q;
	q.push(root);
	linknode* head=NULL;
	linknode* tail=NULL;
	while(q.size()!=0)
	{
		treenode* front=q.front();
		q.pop();
		if(front!=NULL)
		{
			linknode* n=new linknode(front->data);
			if(head==NULL)
			{
				head=n;
				tail=n;
			}
			else if(head!=NULL)
			{
				tail->next=n;
				tail=n;
			}
		}
		if(front->left!=NULL)
		{
			q.push(front->left);
		}
		if(front->right!=NULL)
		{
			q.push(front->right);
		}
		else{
			if(q.size()==0)
			{
				//to avoid infinite looping   //pushing and poping null
				v.push_back(head);
				return v;
			}
			v.push_back(head);
			q.push(NULL); // so that we now about next level
			head=NULL;
			tail=NULL;
		}

		
	}
	return v;
}
int main()
{
	treenode* node=takeinput();
	vector<linknode*> z =levelwiselinkedlist(node);
}
