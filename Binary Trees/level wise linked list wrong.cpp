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

class node
{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data;
        next=NULL;
    }

};

vector<node*> levelwiselinkedlist(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        vector<node*> v;
        v.push_back(NULL);
        return v;    
    }

    vector<node*> v1;

    queue<BinaryTreeNode*>pendingqueue;
    pendingqueue.push(root);
    //null
    while(pendingqueue.size()!=0)
    {
        
        BinaryTreeNode* front=pendingqueue.front();
        pendingqueue.pop();
        node* head=new node(front->data);
        node* current=head;
        if(front->left!=NULL)
        {
            pendingqueue.push(front->left);
            node* temp=new node(front->left->data);
            head->next=temp;
            current=temp;
        }
        
        if(front->right!=NULL)
        {            
            pendingqueue.push(front->right);
            node* temp=new node(front->right->data);
            current->next=temp;
            current=temp;
        }
        v1.push_back(head);
    }
    return v1;

}
//current->next=NULL;

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
    vector<node*> v=levelwiselinkedlist(root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    
}