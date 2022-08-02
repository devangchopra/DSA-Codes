#include<bits/stdc++.h>
using namespace std;
#include "header.h"

int number_of_nodes(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+number_of_nodes(root->left)+number_of_nodes(root->right);
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

    }
    return temp;
}
void level_order_print(BinaryTreeNode* root)
{
    queue<BinaryTreeNode*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode* front=pendingnodes.front();
        pendingnodes.pop();

        cout<<front->data<<" :"<<"   ";

        if(front->left!=NULL)
        {
            cout<<"L"<<" "<<front->left->data<<" ";
            pendingnodes.push(front->left);
        }

        if(front->right!=NULL)
        {
            cout<<"R"<<" "<<front->right->data<<" ";
            pendingnodes.push(front->right);
        }
     
        
        cout<<endl;
    }
}

//Default tree : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1

int main()
{
    BinaryTreeNode* root=takeinput();
    level_order_print(root);
    cout<<number_of_nodes(root);
}