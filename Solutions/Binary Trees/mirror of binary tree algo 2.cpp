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
treenode* takeinput()
{
    int data;
    cin>>data;

    queue<treenode*>pendingqueue;
    treenode* temp=new treenode(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        treenode* front=pendingqueue.front();
        pendingqueue.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            treenode* left=new treenode(ld);
            front->left=left;
            pendingqueue.push(left);
        }
        int rd;
        cin>>rd;

        if(rd!=-1)
        {
            treenode* right=new treenode(rd);
            front->right=right;
            pendingqueue.push(right);       

        }
        
    }
    return temp;
}
treenode* mirrortree(treenode* root)
{
    if(root==NULL)
    {
        return root;
    }
    treenode* t=root->left;
    root->left=root->right;
    root->right=t;
    if(root->left!=NULL)
    {
        mirrortree(root->left);
    }
    if(root->right!=NULL)
    {
        mirrortree(root->right);
    }
    return root;

}
//.* ->
void inorder(treenode* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
	treenode* node=takeinput();
	inorder(node);
	cout<<"After"<<endl;
	node=mirrortree(node);
	inorder(node);

}