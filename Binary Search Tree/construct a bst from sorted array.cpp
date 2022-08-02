#include<bits/stdc++.h>
using namespace std;
#include "header.h"
//add take print function
void print(treenode* root)
{
    //Preorder traversal
    if(root==NULL) return ;

    if(root->data!=NULL)cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
treenode* constrcut_bst(vector<int>v,int start,int end)
{
      if(start > end){    //base case
        return NULL;
    }
    int mid = (start + end) / 2;    //mid of array
    treenode* root = new treenode(v[mid]);    //assign mid as root
    root -> left = constrcut_bst(v, start, mid - 1);    // call to left
    root -> right = constrcut_bst(v, mid + 1, end);    // call to right
    return root;
}
int main()
{
    vector<int>v;
    v={1,2,3,4,5,6,7};
    treenode* root=constrcut_bst(v,0,7);
    print(root);
}

/*
BinaryTreeNode<int> *tree(int *input, int start, int end){
    if(start > end){    //base case
        return NULL;
    }
    int mid = (start + end) / 2;    //mid of array
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);    //assign mid as root
    root -> left = tree(input, start, mid - 1);    // call to left
    root -> right = tree(input, mid + 1, end);    // call to right
    return root;
*/