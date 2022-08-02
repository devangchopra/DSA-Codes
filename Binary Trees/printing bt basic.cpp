#include<bits/stdc++.h>
using namespace std;
#include "header.h"

void printtree(BinaryTreeNode* root)
{
    //recursively
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
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