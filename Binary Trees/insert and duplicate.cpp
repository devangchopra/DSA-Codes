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
void insertDuplicateNode(treenode* root) {
    if(root == NULL){
        return;
    }
    
    insertDuplicateNode(root -> left);
    insertDuplicateNode(root -> right);
    
    treenode* path = root -> left;
    treenode* newNode = new treenode(root -> data);
    
    root -> left = newNode;
    newNode -> left = path;
    
}
void preorder(treenode* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
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
int main()
{
    treenode* root=takeinput();
    insertDuplicateNode(root);
    preorder(root);
}