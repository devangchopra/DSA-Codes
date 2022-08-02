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
void inorder(vector<int> &arr,treenode*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(arr,root->left);    
    arr.push_back(root->data);
    inorder(arr,root->right);    
}
void preorder(vector<int> &arr,treenode*root,int i)
{
    if(root==NULL)
    {
        return;
    }
    root->data=arr[i];
    preorder(arr,root->left,i+1);
    preorder(arr,root->left,i+1);

}
void printtree(treenode* root)
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
int main()
{
    treenode* root=takeinput();
    vector<int>arr;
    inorder(arr,root);
    preorder(arr,root,0);
    printtree(root);

}