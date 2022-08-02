#include <bits/stdc++.h>
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
// considering i/p as in simple binary tree
bool search(treenode* root ,int s)
{
    //Base Case
    if(root==NULL) return false;

    
    if(root->data==s) return true;
    
    //Hypothesis
    bool a,b;
    if(root->data>s)
    {
        //we need to find smaller one
        a=search(root->left,s);
    }
    else if(root->data<s)
    {
        //we need to fin  bigger one
        b=search(root->right,s);
    }

    //induction
    if(a or b)
    {
        return true;
    }
    else {
        return false;
    }
    
 

}
int main()
{
    treenode* root=takeinput();
    int s;
    cin>>s;
    cout<<search(root,s);
}

//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1