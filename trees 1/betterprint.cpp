#include<bits/stdc++.h>
using namespace std;
#include "header.cpp"
void printtree(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    TreeNode* temp=root;
    //never play and loose original root cause its a pointer
    cout<<temp->data<<":";
    for (int i=0;i<temp->children.size();i++)
    {
        cout<<temp->children[i]->data<<" ";
    }
    for (int i=0;i<temp->children.size();i++)
    {
        printtree(temp->children[i]);//minitree
    }
}
int main()
{
    TreeNode* root=new TreeNode(100);
    TreeNode* rc1=new TreeNode(200);
    TreeNode* rc2=new TreeNode(300);
    TreeNode* rc3=new TreeNode(400);
    root->children.push_back(rc1);
    root->children.push_back(rc2);
    root->children.push_back(rc3);
    printtree(root);
    
}