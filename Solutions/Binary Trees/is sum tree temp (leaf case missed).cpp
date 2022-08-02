#include<bits/stdc++.h>
using namespace std;
class Node
{
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
class Solution
{
    public:
    pair<int,bool> helper(Node* root)
    {
    	if(root==NULL)
    	{
    		pair<int,bool>p;
    		p.first=0;
    		p.second=true;
    		return p;
    	}

    	pair<int,bool> leftsubtree=helper(root->left);
    	pair<int,bool> rightsubtree=helper(root->right);

    	bool isleft=leftsubtree.second;
    	bool isright=rightsubtree.second;

    	int leftans=leftsubtree.first;
    	int rightans=rightsubtree.first;

    	pair<int,bool>x;
    	if(isleft and isright)
    	{
    		if(root->data==leftans+rightans)
    		{
    			x.second=true;
    		}
    	}
    	else
    	{
    		x.second=false;
    	}
    	x.first=root->data+leftans+rightans;
    	return x;
    }
    bool isSumTree(Node* root)
    {
        //Base Case
        if(root==NULL) return true;

        pair<int,bool> p=helper(root);
        cout<<p.second;      

    }
};
Node* takeinput()
{
    int data;
    //cout<<"Enter Data"<<" :";
    cin>>data;

    queue<Node*>pendingqueue;
    Node* temp=new Node(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        Node* front=pendingqueue.front();
        pendingqueue.pop();

        int ld;
        //cout<<"Enter Left Child"<<" ";
        cin>>ld;

        if(ld!=-1)
        {
            Node* left=new Node(ld);
            front->left=left;
            pendingqueue.push(left);

        }
              

        int rd;
        //cout<<"Enter Right Child"<<" ";
        cin>>rd;\

        if(rd!=-1)
        {
            Node* right=new Node(rd);
            front->right=right;
            pendingqueue.push(right);        

        }

    }
    return temp;
}
int main()
{
	Node* root=takeinput();
	Solution obj;
	obj.isSumTree(root);
}