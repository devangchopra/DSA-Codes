#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
    public:


        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

    BinaryTreeNode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void print(BinaryTreeNode* root)
{
    queue<BinaryTreeNode*>pq;
    pq.push(root);
    while(pq.size()!=0)
    {
        if(root==NULL) return;
        BinaryTreeNode* front=pq.front();
        pq.pop();
        cout<<front->data<<" ";

        if(front->left!=NULL)
        {
            
            pq.push(front->left);
        }

        if(front->right!=NULL)
        {
            
            pq.push(front->right);
        }

    }
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
    print(root);
}