#include<bits/stdc++.h>
using namespace std;
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
bool search(treenode* root ,int n)
{
	if(root==NULL) return false;
	if(root->data=n) return true;
	if(root->data>n)
	{
		search(root->left,n);
	}
	if(root->data<=n)
	{
		search(root->right,n);
	}
	return false;

}
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

int main()
{
	treenode* root=takeinput();
	int x;
	cin>>x;
	cout<<search(root,x);
}