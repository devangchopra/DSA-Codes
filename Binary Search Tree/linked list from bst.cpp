#include<bits/stdc++.h>
using namespace std;
class treenode
{
    public:
    int data;
    treenode* left;
    treenode* right;

    treenode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
treenode* takeinput()
{
    int data;
    cin>>data;
    queue<treenode*>q;
    treenode* root=new treenode(data);
    q.push(root);
    while(q.size()!=0)
    {
        treenode* temp=q.front();
        q.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            treenode* n=new treenode(ld);
            temp->left=n;
            q.push(n);
        }
        int rd;
        cin>>rd;
        if(rd!=-1)
        {
            treenode* n=new treenode(rd);
            temp->right=n;
            q.push(n);
        }
    }
    return root;
}

node* constrcut_linked_list(treenode* root)
{
    //Base Case
    if(root==NULL)
    {
        node* head=NULL;
        return head;
    }

    //Hypothesis
    node* lefthead=constrcut_linked_list(root->left);
    node* righthead=constrcut_linked_list(root->right);
    node* headroot=new node(root->data);

    //Induction / Small Calculation
    if(lefthead!=NULL)
    {
        node* temp=lefthead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=headroot;
        headroot->next=righthead;
        return lefthead;
    }
    else
    {
        headroot->next=righthead;
        return headroot;
    }
}
void print(node* head)
{
    if(head==NULL) return;
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    treenode* root=takeinput();
    node* head=constrcut_linked_list(root);
    print(head);
}
