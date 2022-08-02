#include<iostream>
using namespace std;
#include "header.h"

BinaryTreeNode* takeinput()
{
    int data;
    cout<<"Enter Data"<<endl;
    cin>>data;
    
    //assuming if data =-1 ...stop there

    if(data==-1)
    {
        return NULL;
    }

    BinaryTreeNode* root=new BinaryTreeNode(data);
    BinaryTreeNode* left=takeinput();
    BinaryTreeNode* right=takeinput();

    root->left=left;
    root->right=right;
    return root;
}
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
    BinaryTreeNode* root=takeinput();
    printtree(root);
}