#include<bits/stdc++.h>
using namespace std;
#include "header.h"

void nodesWithoutSibling(BinaryTreeNode *root) {
    
    if(root == NULL){
        return;
    }
    
    if(root -> left == NULL && root -> right != NULL){
        cout << root -> right -> data << endl;
    }
    else if(root -> left != NULL && root -> right == NULL){
         cout << root -> left -> data << endl;
    }
    
    nodesWithoutSibling(root -> left);
    nodesWithoutSibling(root -> right);
}

BinaryTreeNode* takeinput()
{
    int data;
    cin>>data;

    queue<BinaryTreeNode*>pendingqueue;
    BinaryTreeNode* temp=new BinaryTreeNode(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        BinaryTreeNode* front=pendingqueue.front();
        pendingqueue.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            BinaryTreeNode* left=new BinaryTreeNode(ld);
            front->left=left;
            pendingqueue.push(left);
        }
        int rd;
        cin>>rd;

        if(rd!=-1)
        {
            BinaryTreeNode* right=new BinaryTreeNode(rd);
            front->right=right;
            pendingqueue.push(right);       

        }
        
    }
    return temp;
}
int main()
{
    BinaryTreeNode* root=takeinput();
    nodesWithoutSibling(root);
}
