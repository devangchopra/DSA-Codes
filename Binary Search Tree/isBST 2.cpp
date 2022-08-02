#include<bits/stdc++.h>
using namespace std;
#include "header.h"
bool isBST2(treenode* root,int min=INT_MIN , int max=INT_MAX)
{
    if(root==NULL) return true;
    if(root->data<min or root->data>max) return false;

    bool isleftok=isBST2(root->left,min,root->data-1);
    bool isrightok=isBST2(root->right,root->data+1,max);

    return isleftok and isrightok;    
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
    cout<<isBST2(root);
}

////4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1