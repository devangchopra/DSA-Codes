#include<bits/stdc++.h>
using namespace std;
#include"binary tree node header.h"
void preorder_recursive(treenode* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}
void preorder_iterative(treenode* root)
{   
    //recursive -> iterative we will use stack.....system maitains recursive stack
    stack<treenode*>s;
    s.push(root);
    treenode* curr=NULL;
    while(s.empty()==false)
    {
        treenode* temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
        {
            s.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            s.push(temp->left);
        }

    }
}
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
int main()
{
    treenode* root=takeinput();
    cout<<"This is recursive"<<endl;
    preorder_recursive(root);
    cout<<endl;
    cout<<"This is iterative"<<endl;
    preorder_iterative(root);

}