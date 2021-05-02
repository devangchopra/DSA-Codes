#include<bits/stdc++.h>
#include "header.cpp"
using namespace std;

void printtree(TreeNode* root)
{
    if(root=NULL)  //handling the base case
    {
        return;
    }

    cout<<root->data<<" ";
    
    for (int i=0;i<root->children.size();i++) // for loop is handling base case
    {
        printtree(root->children[i]);
        //recursion 
    }
}


int main()
{
    //dynamic allocation :: space and faster
    TreeNode* root= new TreeNode(10);
    TreeNode* c1= new TreeNode(20);
    TreeNode* c2=new TreeNode(30);

    //whenver we have a pointer object...we use -> in place of dot .
    root->children.push_back(c1);
    // i  have not written &c1 because c1 is already a pointer and children vector also consists of pointers

    root->children.push_back(c2);
    printtree(root);

}