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
int sum=0;
void helper(treenode* root)
{
    if(root==NULL)
        return;

    helper(root->right);
    sum=sum+root->data;
    root->data=sum;
    helper(root->left);
      
}
void replace(treenode* root)
{
    helper(root);
}
void print(treenode* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main(int argc, char const *argv[])
{
    treenode* root=takeinput();
    print(root);
    replace(root);
    cout<<"Now "<<endl;
    print(root);
    return 0;
}