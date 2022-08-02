#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
    public:


        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

    BinaryTreeNode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
BinaryTreeNode* takeinput()
{
    int data;
    cin>>data;

    queue<BinaryTreeNode*>pendingqueue;
    BinaryTreeNode* temp=new BinaryTreeNode(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        BinaryTreeNode* front=pendingqueue.front();
        pendingqueue.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            BinaryTreeNode* left=new BinaryTreeNode(ld);
            front->left=left;
            pendingqueue.push(left);
        }
        int rd;
        cin>>rd;

        if(rd!=-1)
        {
            BinaryTreeNode* right=new BinaryTreeNode(rd);
            front->right=right;
            pendingqueue.push(right);       

        }
        
    }
    return temp;
}
pair<bool,int> unival_tree(BinaryTreeNode* root)
{
	
	if(root==NULL)
	{
		//Null Node
		pair<bool,int> p;
		p={1,0};
		return p;
	}

	if(root->left==NULL and root->right==NULL)
	{
		//Leaf Node
		pair<int,bool>p;
		p={1,1};
		return p;
	}

	pair<bool,int> leftans=unival_tree(root->left);
	pair<bool,int> rightans=unival_tree(root->right);

	pair<bool,int> ans;
	int count=0;
	if(leftans.first)
	{
		count++;
	}
	if(rightans.first)
	{
		count++;
	}
	ans.second=count;

	bool flag=false;

	if(leftans.first and rightans.first)
	{
		if(root->data==root->left->data and root->data==root->right->data)
		{
			flag=true;
		}
	}
	ans.first=true;
	return ans;
}

int main(int argc, char const *argv[])
{
	BinaryTreeNode* root=takeinput();
	pair<bool,int> p = unival_tree(root);


	cout<< p.second << " ";
	
	
	return 0;
}