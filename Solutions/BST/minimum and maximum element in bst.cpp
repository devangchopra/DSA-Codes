#include <bits/stdc++.h>
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
    if(root==NULL)
        return 0;
    int leftsekyaya;
    if(root->left)
        leftsekyaya=minimum(root->left);
    
    else{
        return root->data;
    }
    return leftsekyaya;
}
int maximum(treenode* root)
{
    if(root==NULL)
        return 0;
    int rightsekyaaya;
    if(root->right)
        rightsekyaaya=maximum(root->right);
    
    else{
        return root->data;
    }
    return rightsekyaaya;
}
int main(int argc, char const *argv[])
{
    treenode* root=takeinput();
    cout<<minimum(root)<<endl;
    cout<<maximum(root);
    return 0;
}