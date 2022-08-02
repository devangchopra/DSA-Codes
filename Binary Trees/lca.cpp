#include <bits/stdc++.h>
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
TreeNode* lca(TreeNode* root ,TreeNode* n1 ,TreeNode*  n2 )
    {
        if(root==NULL)
        {
            return NULL;
        }
       //Your code here 
       if(root->val==n1->val or root->val==n2->val)
       {
           return root;
       }
       
       TreeNode* leftans=lca(root->left,n1,n2);
       TreeNode* rightans=lca(root->right,n1,n2);
       
       if(leftans==NULL and rightans!=NULL)
       {
         return rightans;
       }
       if(leftans!=NULL and rightans!=NULL)
       {
           return root;
       }
       if(leftans!=NULL and rightans==NULL)
       {
           return leftans;
       }
       else
       {
           return NULL;
       }
       
       
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return lca(root,p,q);
        
    }
int main()
{
    treenode* root=takeinput();
    int a,b;
    cin>>a>>b;
    cout<<lca(root,a,b);
  
}

//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1