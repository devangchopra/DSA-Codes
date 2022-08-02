#include <bits/stdc++.h>
using namespace std;
class  treenode
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
    queue<treenode*>q;
    treenode* root=new treenode(data);
    q.push(root);
    while(q.size()!=0)
    {
        treenode* temp=q.front();
        q.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            treenode* n=new treenode(ld);
            temp->left=n;
            q.push(n);
        }
        int rd;
        cin>>rd;
        if(rd!=-1)
        {
            treenode* n=new treenode(rd);
            temp->right=n;
            q.push(n);
        }
    }
    return root;
}


int minimum(treenode* root)
{
	if(root==NULL) return INT_MAX;
	return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(treenode* root)
{
	if(root==NULL) return INT_MIN;
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST(treenode* root)
{
	if(root==NULL) return true;

	//Hypothesis
	int leftmax=maximum(root->left);
	int rightmin=minimum(root->right);


	//Induction
	bool output=(root->data>leftmax) and (root->data<=rightmin) and isBST(root->left) and isBST(root->right);
	return output;
}

int main()
{
	treenode* root=takeinput();
	cout<<isBST(root);
}