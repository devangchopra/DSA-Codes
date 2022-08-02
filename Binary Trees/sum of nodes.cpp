#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};

Node* takeinput()
{

	int data;
	cin>>data;
	Node* temp=new Node(data);
	queue<Node*>pq;
	pq.push(temp);
	while(pq.size()!=0)
	{
		Node* front=pq.front();
		pq.pop();

		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			Node* leftchild=new Node(leftdata);
			front->left=leftchild;
			pq.push(leftchild);
		}


		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			Node* rightchild=new Node(rightdata);
			front->right=rightchild;
			pq.push(rightchild);
		}
	}
	return temp;
}
int sumoofnodessimple(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int sum=root->data;
	return sum+sumoofnodessimple(root->left)+sumoofnodessimple(root->right);

}
int sumoofnodes(Node* root)
{
	//Base Case
	if(root==NULL)
	{
		return 0;
	}

	//Hypothesis
	int sumleft=0;
	if(root->left!=NULL)
	{
		sumleft=sumoofnodes(root->left);
	}
	int sumright=0;
	if(root->right!=NULL)
	{
		sumright=sumoofnodes(root->right);
	}
	
	

	//Induction
	return root->data+sumleft+sumright;
	
}
int main()
{
	Node* root=takeinput();
	cout<<sumoofnodes(root);
}
