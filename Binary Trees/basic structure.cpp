#include<bits/stdc++.h>
using namespace std;
#include "header.h"

int main()
{
    BinaryTreeNode* root=new BinaryTreeNode(1);
    BinaryTreeNode* left=new BinaryTreeNode(2);
    BinaryTreeNode* right=new BinaryTreeNode(3);

    root->left=left;
    root->right=right;   
    cout<<"Hello World";

}