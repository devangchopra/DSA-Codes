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
void inorder(queue<int> &q,treenode*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(q,root->left);    
    q.push(root->data);
    inorder(q,root->right);    
}
void preorder(queue<int> &q,treenode*root)
{
    if(root==NULL)
    {
        return;
    }
    root->data=q.front();
    q.pop();
    preorder(q,root->left);
    preorder(q,root->right);

}
void print(treenode* root)
{
    queue<treenode*>pq;
    pq.push(root);
    while(pq.size()!=0)
    {
        if(root==NULL) return;
        treenode* front=pq.front();
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
int main()
{
    treenode* root=takeinput();
    queue<int>q;
    inorder(q,root);
    preorder(q,root);
    cout<<endl;
    print(root);

}