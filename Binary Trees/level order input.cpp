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

BinaryTreeNode* takeinput()
{
    int data;
    cout<<"Enter Data"<<" :";
    cin>>data;

    queue<BinaryTreeNode*>pendingqueue;
    BinaryTreeNode* temp=new BinaryTreeNode(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        BinaryTreeNode* front=pendingqueue.front();
        pendingqueue.pop();

        int ld;
        cout<<"Enter Left Child"<<" ";
        cin>>ld;

       /* if(ld==-1)     This idea is not good because if one node is breaked whole loop will be breaked ..we dont want that
        {
            break;
        }
         */ 


        if(ld!=-1)
        {
            BinaryTreeNode* left=new BinaryTreeNode(ld);
            front->left=left;
            pendingqueue.push(left);

        }
        
        

        int rd;
        cout<<"Enter Right Child"<<" ";
        cin>>rd;\

        if(rd!=-1)
        {
            BinaryTreeNode* right=new BinaryTreeNode(rd);
            front->right=right;
            pendingqueue.push(right);        

        }

        /*if(rd==-1)
        {
            break;
        }*/
        
    }
    return temp;
}
int main()
{
    BinaryTreeNode* root=takeinput();
    printtree(root);
}