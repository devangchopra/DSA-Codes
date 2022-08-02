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
void level_depth(treenode* root)
{  
    queue<treenode*>q;
    q.push(root);
    cout<<root->data<<endl;
    while(q.size()!=0)
    {
        int n=q.size();
        while(n>0)
        {
            treenode* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            n--;
        }
        cout<<endl;      
        
    }
}
int main()
{
    treenode* root=takeinput();
    level_depth(root);
}