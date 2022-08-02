#include<bits/stdc++.h>
using namespace std;
#include "header.h"
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

void print_in_range(treenode* root,int x,int y)
{   
    if(root==NULL)
    {
        return;
    }

    if(root->data>x)
    {
        print_in_range(root->left,x,y);
    }
    if(root->data<=y)
    {
        print_in_range(root->right,x,y);
    }
        if(root->data>=x and root->data<=y)
    {
        cout<<root->data<<" ";
    }

}
int main()
{
    treenode* root=takeinput();
    int x,y;
    cin>>x>>y;   
    print_in_range(root,x,y);
}
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1