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

pair<int,bool> balanced(node* root)
{
	//Base Case
	if(root==NULL)
	{
		pair<int,bool>p;
		p.first=0;
		p.second=1;
		return p;
	}

	//Hypothesis
	pair<int,bool> leftsubtree=balanced(root->left);
	pair<int,bool> rightsubtree=balanced(root->right);

	
	int leftheight=leftsubtree.first;
	bool ansleft=leftsubtree.second;

	int rightheight=rightsubtree.first;
	bool ansright=rightsubtree.second;

	//Induction
	int height=1+max(leftheight,rightheight);
	pair<int,bool>p;
	p.first=height;
	if(ansleft==ansright and ansleft==1)
	{
		if(abs(leftheight-rightheight<=1))
		{
			p.second=1;
		}
	}
	else
	{
		p.second=false;
	}



	

	return p;
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
	pair<int,bool> x=balanced(root);
	cout<<x.second;

}

//5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

//1 2 3 -1 -1 -1 -1

