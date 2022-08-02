#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;

	node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	return 1+max(height(root->left),height(root->right));
}
bool balanced(node* root)
{
	//1.Base case
	if(root==NULL)
	{
		return true;
	}

	/*
		root
	   /    \
	subtree  subtree

	*/


	//2.Hypothesis
	bool a=balanced(root->left);
	bool b=balanced(root->right);

	//3.Induction
	if(! (abs(height(root->left)-height(root->right))<=1))
		return false;
	else
	{
		return (a and b);
	}
}
node* takeinput()
{
    int data;
    cin>>data;

    queue<node*>pendingqueue;
    node* temp=new node(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        node* front=pendingqueue.front();
        pendingqueue.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            node* left=new node(ld);
            front->left=left;
            pendingqueue.push(left);
        }
        int rd;
        cin>>rd;

        if(rd!=-1)
        {
       		node* right=new node(rd);
            front->right=right;
            pendingqueue.push(right);       

        }
        
    }
    return temp;
}
int main()
{
	node* root=takeinput();
	cout<<balanced(root);
}

//5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

//1 2 3 -1 -1 -1 -1

