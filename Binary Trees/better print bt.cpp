#include<bits/stdc++.h>
using namespace std;
#include "header.h"

void printtree(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<" "<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<" "<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
int main()
{
    BinaryTreeNode* root=new BinaryTreeNode(1);
    BinaryTreeNode* left=new BinaryTreeNode(2);
    BinaryTreeNode* right=new BinaryTreeNode(3);
    root->left=left;
    root->right=right;
    printtree(root);
}