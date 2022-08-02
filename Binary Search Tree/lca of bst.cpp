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

int lcabst(treenode* root,int a,int b)
{
    if(root==NULL) return NULL;
    if(a==b and a==root->data)
    {
        return root->data;
    }
    else if(a>root->data and b>root->data)
    {
        return lcabst(root->right,a,b);
    }
    else if(a<root->data and b<root->data)
    {
        return lcabst(root->left,a,b);
    }
    else
    {
        //same  case of bt
        int left = lcabst(root -> left, a, b);
        int right = lcabst(root -> right, a, b);
        
        if(left == NULL && right == NULL){
            return -1;
        }
        else if(left == NULL && right != NULL){
            return right;
        }
        else if(left != NULL && right == NULL){
            return left;
        }
        else{
            return root -> data;
        }
    }
    
}
int main()
{
    treenode* root=takeinput();
    int a,b;
    cin>>a>>b;
    cout<<lcabst(root,a,b);
    return 0;
}
