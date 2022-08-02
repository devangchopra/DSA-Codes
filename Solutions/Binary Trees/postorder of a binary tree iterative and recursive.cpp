#include<bits/stdc++.h>
using namespace std;
#include "binary tree node header.h"
void recursive(treenode* root)
{
    if(root==NULL) return;
    recursive(root->left);
    recursive(root->right);
    cout<<root->data<<" ";
}
void iterative(treenode* root)
{
    //we need to use our own stack
    if(root==NULL) return;
    stack<treenode*>s1;
    s1.push(root);
    stack<treenode*>s2;
    while(s1.size()!=0)
    {
        treenode* temp=s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left!=NULL)
        {
            s1.push(temp->left);
        }

        if(temp->right!=NULL)
        {
            s1.push(temp->right);
        }
     
    }
    while(s2.size()!=0)
    {
        treenode* temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
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
    recursive(root);
    cout<<endl;
    iterative(root);
}