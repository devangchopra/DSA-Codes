#include<bits/stdc++.h>
using namespace std;
#include "header.h"
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

void zigzagorder(BinaryTreeNode* root)
{
    if(root==NULL) return;
    queue<BinaryTreeNode*>q;
    q.push(root);
    int level=0;
    while(q.size()!=0)
    {
        BinaryTreeNode* temp=q.front();
        q.pop();
        level++;
        if(level%2!=0)
        {
            //odd
            cout<<temp->data<<" ";
        }
    
        else if(level%2==0)
        {
        
            if(q.size()!=0)
            {
                BinaryTreeNode* temp2=q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                     q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                if(temp2->left!=NULL)
                {
                    q.push(temp2->left);
                }
                if(temp2->right!=NULL)
                {
                    q.push(temp2->right);
                }
                cout<<temp2->data<<" "<<temp->data<<" ";
                //level++;
            }
            if(q.size()==0)
            {
                cout<<temp->data<<" ";
            }
            continue;
        }
                if(temp->left!=NULL)
                {
                     q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }


        
    }

}

void zigzagorder2(BinaryTreeNode* root)
{
    stack<BinaryTreeNode*>s1;
    s1.push(root);
    stack<BinaryTreeNode*>s2;
    while(s1.size()!=0 or s2.size()!=0)
    {
        if(s1.empty()==false)
        {
            //pop .. print
            BinaryTreeNode* temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                s2.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                s2.push(temp->right);
            }
        }
        else if(s2.empty()==false)
        {
            //cout<<endl;
            BinaryTreeNode* temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->right!=NULL)
            {
                s1.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                s1.push(temp->left);
            }
            
        }
    }
}





int main()
{
    BinaryTreeNode* root=takeinput();
    zigzagorder2(root);
}